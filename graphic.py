import turtle

t = turtle.Turtle()
wn = turtle.Screen()
wn.title("T800")

t.pensize(2)

graph = open("./graph", "r")
t.write("(0,0)")
for line in graph:
    if line[0] == "r":
        t.left(float(line[1:]))
    elif line[0] == "w":
        t.forward(float(line[1:]))

wn.exitonclick()
