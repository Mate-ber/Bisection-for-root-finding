import matplotlib.pyplot as plt


def read_data(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        data = [list(map(float, line.strip().split())) for line in lines]
    return zip(*data)


def plot_graph(x, y, label):
    plt.plot(x, y, marker='o', linestyle='-', label=label)


if __name__ == "__main__":
    file_path1 = 'data1.txt'
    file_path2 = 'data2.txt'
    file_path3 = 'data3.txt'

    x1, y1 = read_data(file_path1)
    x2, y2 = read_data(file_path2)
    x3, y3 = read_data(file_path3)

    plot_graph(y3, x3, label='bisection')
    plot_graph(y1, x1, label='Newton')
    plot_graph(y2, x2, label='Newton and bisection')

    plt.yscale('log')

    plt.title('Graphs')
    plt.xlabel('iterations')
    plt.ylabel('error')
    plt.legend()
    plt.grid(True)
    plt.show()
