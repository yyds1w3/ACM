import random

with open("./OI/P2392.in", "w") as f:
    times = 100;
    for j in range(times):
        f.write(f"times: {j}\n")
        s1 = random.randint(1, 20)
        s2 = random.randint(1, 20)
        s3 = random.randint(1, 20)
        s4 = random.randint(1, 20)
        f.write(f"{s1} {s2} {s3} {s4}\n")
        for i in range(s1):
            f.write(f"{random.randint(1,60)} ")
        f.write("\n")
        for i in range(s2):
            f.write(f"{random.randint(1,60)} ")
        f.write("\n")
        for i in range(s3):
            f.write(f"{random.randint(1,60)} ")
        f.write("\n")
        for i in range(s4):
            f.write(f"{random.randint(1,60)} ")
        f.write("\n")

