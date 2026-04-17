from datetime import datetime
now = datetime.now()
print(f"Data: {now}")
format_now = now.strftime("%d-%m-%Y %H:%M")
print(f"Data formatata: {format_now}")
