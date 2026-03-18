import subprocess
import sys
import time
from datetime import datetime

def get_explorer_processes():
    """Get all explorer.exe processes with their PID, StartTime, and CommandLine"""
    cmd = 'Get-Process explorer | ForEach-Object { [PSCustomObject]@{ Id = $_.Id; StartTime = $_.StartTime; CommandLine = (Get-CimInstance Win32_Process -Filter "ProcessId = $($_.Id)").CommandLine } } | ConvertTo-Json'
    result = subprocess.run(
        ['powershell', '-NoProfile', '-Command', cmd],
        capture_output=True,
        text=True
    )
    
    if result.returncode != 0:
        print(f"Error getting processes: {result.stderr}")
        print("\n===================================================================================================================================")
        time.sleep(3)
        sys.exit(1)
    
    import json
    processes = json.loads(result.stdout)
    
    # Handle single process (not a list)
    if isinstance(processes, dict):
        processes = [processes]
    
    return processes

def parse_datetime(date_str):
    """Parse PowerShell DateTime string"""
    # Format: /Date(1738713437000)/
    timestamp = int(date_str.replace('/Date(', '').replace(')/', '')) / 1000
    return datetime.fromtimestamp(timestamp)

def is_tool_mod(command_line):
    """Check if this is a Windhawk tool mod process"""
    if not command_line:
        return False
    return '-tool-mod' in command_line

def kill_explorers(pids_to_kill):
    """Kill specific explorer processes by PID"""
    if not pids_to_kill:
        return True
    
    pids_str = ','.join(map(str, pids_to_kill))
    cmd = f'Get-Process explorer | Where-Object {{$_.Id -in @({pids_str})}} | Stop-Process -Force'
    result = subprocess.run(
        ['powershell', '-NoProfile', '-Command', cmd],
        capture_output=True,
        text=True
    )
    
    if result.returncode != 0:
        print(f"Warning: {result.stderr}")
        time.sleep(2)
    
    return result.returncode == 0

def restart_explorer():
    """Restart explorer.exe"""
    print("\n🔄 Restarting explorer.exe...")
    time.sleep(1)
    
    result = subprocess.run(
        ['powershell', '-NoProfile', '-Command', 'Start-Process explorer.exe'],
        capture_output=True,
        text=True
    )
    
    if result.returncode == 0:
        print("✅ Explorer restarted successfully!")
    else:
        print(f"⚠️  Warning: {result.stderr}")
        print("You may need to manually restart explorer from Task Manager.")
    
    time.sleep(2)

def main():
    print("-------------------------------------------------------------------------------------------------------------------------------")
    print("Finding all explorer.exe processes...")
    time.sleep(1)
    
    try:
        processes = get_explorer_processes()
    except Exception as e:
        print(f"\n❌ Error: {e}")
        print("\n===================================================================================================================================")
        time.sleep(3)
        sys.exit(1)
    
    if not processes:
        print("No explorer.exe processes found!")
        print("\n===================================================================================================================================")
        time.sleep(2)
        sys.exit(1)
    
    print(f"\nFound {len(processes)} explorer.exe process(es):\n")
    time.sleep(0.5)
    
    # Parse and categorize processes
    main_explorers = []
    tool_mods = []
    
    for proc in processes:
        pid = proc['Id']
        start_time = parse_datetime(proc['StartTime'])
        command_line = proc.get('CommandLine', '')
        
        if is_tool_mod(command_line):
            tool_mods.append((pid, start_time, command_line))
            print(f"  🛠️  PID {pid}: Tool Mod (started {start_time.strftime('%Y-%m-%d %I:%M:%S %p')})")
            print(f"      Command: {command_line}")
        else:
            main_explorers.append((pid, start_time))
            print(f"  📂 PID {pid}: Explorer Shell (started {start_time.strftime('%Y-%m-%d %I:%M:%S %p')})")
        
        time.sleep(0.3)
    
    time.sleep(1)
    
    if not main_explorers:
        print("\n⚠️  No main explorer.exe processes found (only tool mods)!")
        print("\n===================================================================================================================================")
        time.sleep(3)
        sys.exit(0)
    
    # Sort main explorers by start time (oldest first)
    main_explorers.sort(key=lambda x: x[1])
    
    oldest_pid = main_explorers[0][0]
    oldest_time = main_explorers[0][1]
    
    print(f"\n✅ Oldest main shell: PID {oldest_pid} (started {oldest_time.strftime('%Y-%m-%d %I:%M:%S %p')})")
    time.sleep(1)
    
    # Build combined selection list
    selection_map = []  # List of (index, type, pid, description)
    index = 1
    
    print(f"\n📋 Select which processes to CLOSE:\n")
    time.sleep(0.5)
    
    # Add tool mods first
    for pid, _, cmd in tool_mods:
        mod_name = cmd.split('"')[-2] if '"' in cmd else "unknown"
        print(f"  [{index}] 🛠️  PID {pid}: Tool Mod ({mod_name})")
        selection_map.append((index, 'tool_mod', pid, mod_name))
        index += 1
        time.sleep(0.3)
    
    # Add main explorer shells
    for pid, start_time in main_explorers:
        status = " ⚠️ DESKTOP SHELL" if pid == oldest_pid else ""
        print(f"  [{index}] 📂 PID {pid}: Main Explorer{status}")
        selection_map.append((index, 'main_explorer', pid, f"started {start_time.strftime('%Y-%m-%d %I:%M:%S %p')}"))
        index += 1
        time.sleep(0.3)
    
    print(f"\nEnter processes to CLOSE (e.g., '1 2' or 'all' or leave blank for 'none'):")
    response = input("> ").strip().lower()
    
    processes_to_close = []
    
    if response == 'all':
        processes_to_close = [item[2] for item in selection_map]  # All PIDs
    elif response == '' or response == 'none':
        processes_to_close = []
        print("\nNothing to kill.")
        print("\n===================================================================================================================================")
        time.sleep(2)
        sys.exit(0)
    else:
        try:
            # Split by any whitespace (spaces, tabs, etc.)
            indices = response.split()
            close_indices = [int(idx) for idx in indices]
            
            for idx, proc_type, pid, desc in selection_map:
                if idx in close_indices:
                    processes_to_close.append(pid)
        except ValueError:
            print("\nInvalid input. Nothing to kill.")
            print("\n===================================================================================================================================")
            time.sleep(2)
            sys.exit(0)
    
    time.sleep(1)
    
    # Check if killing main explorer
    main_explorers_to_close = [pid for pid in processes_to_close if pid in [p for p, _ in main_explorers]]
    killing_all_main = len(main_explorers_to_close) == len(main_explorers)
    
    # Commented out warning confirmation - just proceed
    # if main_explorers_to_close:
    #     print("\n⚠️⚠️⚠️  WARNING: You selected main explorer shell(s)! Your desktop will disappear! ⚠️⚠️⚠️")
    # 
    # response = input("\nProceed? (y/n): ").strip().lower()
    # 
    # if response != 'y':
    #     print("\nCancelled.")
    #     print("\n===================================================================================================================================")
    #     time.sleep(2)
    #     sys.exit(0)
    
    # Kill processes
    print(f"\nKilling processes...")
    time.sleep(1)
    
    if not kill_explorers(processes_to_close):
        print("❌ Failed to kill some processes. Try running as Administrator.")
        print("\n===================================================================================================================================")
        time.sleep(3)
        sys.exit(1)
    
    print("✅ Done! Processes terminated.")
    
    # If killed all main explorers, wait then restart
    if killing_all_main:
        print("\n⏸️  Press ENTER to restart explorer...")
        input()  # Just wait for Enter key
        restart_explorer()
    
    print("\n===================================================================================================================================")
    time.sleep(2)

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n\n⚠️  Interrupted by user.")
        print("\n===================================================================================================================================")
        time.sleep(5)
        sys.exit(0)
    except Exception as e:
        print(f"\n❌ Unexpected error: {e}")
        print("\n===================================================================================================================================")
        time.sleep(5)
        sys.exit(1)