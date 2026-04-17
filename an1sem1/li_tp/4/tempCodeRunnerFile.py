
with open("mediile.csv", "w", newline="") as f:
    scrie=csv.DictWriter(f,fieldnames=["nume","media"])
    scrie.writeheader()
    scrie.writerows(media_generala)