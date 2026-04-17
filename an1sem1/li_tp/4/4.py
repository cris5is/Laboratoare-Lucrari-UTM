import csv

tasks = []

def task_add():
    task = input("Task: ")
    prioritate = input("Prioritate (mica/mare): ")
    status = "in progress"
    tasks.append({"task": task, "prioritate": prioritate, "status": status})

def finish_task(nr):
    if 1 <= nr <= len(tasks):
        tasks[nr-1]["status"] = "gata"
    else:
        print("Element in afara limitei\n")

def export_csv():
    with open("taskuri.csv", "w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=["task", "prioritate", "status"])
        writer.writeheader()
        writer.writerows(tasks)

def printlist():
    for item in tasks:
        print(f"Task: {item['task']} Prioritate: {item['prioritate']} Status:{item['status']}\n")

option=0
while option!=5:
    option=int(input("alegeti optiunea: \n 1. adaugati task\n 2. finisati task\n 3. aratati lista de taskuri\n 4. export in csv\n 5.iesire din program\n"))
    match option:
        case 1:
            task_add()
        case 2:
            printlist()
            nr=int(input("Alegeti tasku: "))
            finish_task(nr)
        case 3:
            printlist()
        case 4:
            export_csv()
        case 5:
            pass
        case _:
            print("Alegeti o optiune valabila\n")