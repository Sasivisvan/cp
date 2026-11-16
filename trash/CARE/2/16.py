class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def build_bst(arr):
    if not arr or arr[0] == 'N':
        return None

    root = TreeNode(int(arr[0]))
    q = [root]
    i = 1

    while q and i < len(arr):
        node = q.pop(0)

        if i < len(arr) and arr[i] != 'N':
            node.left = TreeNode(int(arr[i]))
            q.append(node.left)
        i += 1

        if i < len(arr) and arr[i] != 'N':
            node.right = TreeNode(int(arr[i]))
            q.append(node.right)
        i += 1

    return root


def count_range(node, low, high):
    if node is None:
        return 0

    if low <= node.val <= high:
        return (
            1
            + count_range(node.left, low, high)
            + count_range(node.right, low, high)
        )
    elif node.val < low:
        return count_range(node.right, low, high)
    else:
        return count_range(node.left, low, high)


arr = input().split()
low, high = map(int, input().split())

root = build_bst(arr)
ans = count_range(root, low, high)

print(ans)