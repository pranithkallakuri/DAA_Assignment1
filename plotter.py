import matplotlib.pyplot as plt
import matplotlib.patches as patches

rect_coords = []
#rect_coords = [[10, 20, 10, 30], [15, 40, 10, 25,], [15, 20, 15, 30]]
contours_horiz = []
contours_verti = []
with open("points.csv", 'r') as file1:
    flag = 0
    for line in file1:
        if flag == 0 and line == "\n":
            flag = 1
            continue
        if flag == 1 and line == "\n":
            flag = 2
            continue
        if flag == 0:
            rect_coords.append([int(s) for s in line.split(", ")])
        if flag == 1:
            contours_horiz.append([int(s) for s in line.split(", ")])
        if flag == 2:
            contours_verti.append([int(s) for s in line.split(", ")])

print(rect_coords)
print(contours_horiz)
print(contours_verti)

fig, ax = plt.subplots()
for li in rect_coords:
    ax.add_patch(
        patches.Rectangle(
            (li[0], li[2]),
            (li[1]-li[0]),
            (li[3]-li[2]),
            edgecolor='black',
            fill=False
        )
    )
ax.plot()
for li in contours_horiz:
    ax.plot([li[0], li[1]], [li[2], li[2]], color='red')
for li in contours_verti:
    ax.plot([li[2], li[2]], [li[0], li[1]], color='red')

plt.show()