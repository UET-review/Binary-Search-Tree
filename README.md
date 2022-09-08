# Cây nhị phân tìm kiếm
## Định nghĩa
* **Cây** (tree): bao gồm tập các đỉnh (node) và các mối liên hệ giữa đỉnh cha và đỉnh con (tức cạnh)
* **Cây nhị phân** (binary tree): là cây mà mỗi đỉnh trong (internal node) có nhiều nhất 2 đỉnh con là đỉnh con trái và đỉnh con phải.
* **Cây nhị phân tìm kiếm**: là cây nhị phân thỏa mãn điều kiện:
  * Tất cả các node con bên trái đều nhỏ hơn node hiện tại.
  * Tất cả các node con bên phải đều lơn hơn code hiện tại.
* Biểu diễn cây nhị phân tìm kiếm bằng danh sách liên kết.

![binary_search_tr](https://user-images.githubusercontent.com/63502091/189054665-701c8356-0beb-45ab-8701-019095ecf988.png)

## Cài đặt và các phép toán
* Tìm kiếm 
* Chèn đỉnh
* Xóa đỉnh
* Duyệt cây tìm kiếm nhị phân 
    * Pre-order traversal  [Node -> L -> R]
    * In-order traversal   [L -> Node -> R]
    * Post-order traversal [L -> R .> Node]
