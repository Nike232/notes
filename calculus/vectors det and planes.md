
## Vectors, Determinants, and Planes

### Area and Determinants

#### Two-Dimensional Vectors
- **Determinant of Two Vectors**: The determinant of two 2D vectors $\mathbf{a} = \begin{pmatrix} a_1 \\ a_2 \end{pmatrix}$ and $\mathbf{b} = \begin{pmatrix} b_1 \\ b_2 \end{pmatrix}$ is given by:
  $$
  \text{det}(\mathbf{a}, \mathbf{b}) = a_1 b_2 - a_2 b_1
  $$
  This determinant represents the area of the parallelogram formed by the vectors $\mathbf{a}$ and $\mathbf{b}$.

  ![](https://pic1.imgdb.cn/item/67f5e8fd88c538a9b5c6f86c.png)

#### Three-Dimensional Vectors
- **Determinant of Three Vectors**: The determinant of three 3D vectors $\mathbf{a} = \begin{pmatrix} a_1 \\ a_2 \\ a_3 \end{pmatrix}$, $\mathbf{b} = \begin{pmatrix} b_1 \\ b_2 \\ b_3 \end{pmatrix}$, and $\mathbf{c} = \begin{pmatrix} c_1 \\ c_2 \\ c_3 \end{pmatrix}$ is given by:
  $$
  \text{det}(\mathbf{a}, \mathbf{b}, \mathbf{c}) = \begin{vmatrix}
  a_1 & a_2 & a_3 \\
  b_1 & b_2 & b_3 \\
  c_1 & c_2 & c_3
  \end{vmatrix}
  $$
  This determinant represents the volume of the parallelepiped (parallel six-sided figure) formed by the vectors $\mathbf{a}$, $\mathbf{b}$, and $\mathbf{c}$. The sign of the determinant indicates the orientation of the vectors.

  ![](https://pic1.imgdb.cn/item/67f5e92e88c538a9b5c6f8e7.png)

  ![](https://pic1.imgdb.cn/item/67f5e95f88c538a9b5c6f962.png)

### Cross Product

- **Definition**: The cross product of two vectors $\mathbf{a}$ and $\mathbf{b}$, denoted as $\mathbf{a} \times \mathbf{b}$, is a vector that is perpendicular to both $\mathbf{a}$ and $\mathbf{b}$.

  ![](https://pic1.imgdb.cn/item/67f5e95f88c538a9b5c6f962.png)

- **Magnitude of Cross Product**:
  - **Algebraic Approach**: The magnitude of the cross product is given by:
    $$
    |\mathbf{a} \times \mathbf{b}| = |\mathbf{a}| |\mathbf{b}| \sin(\theta)
    $$
    where $\theta$ is the angle between the vectors $\mathbf{a}$ and $\mathbf{b}$.
  - **Geometric Approach**: The magnitude can also be calculated using the determinant of a matrix:
    $$
    |\mathbf{a} \times \mathbf{b}| = \begin{vmatrix}
    \mathbf{i} & \mathbf{j} & \mathbf{k} \\
    a_1 & a_2 & a_3 \\
    b_1 & b_2 & b_3
    \end{vmatrix}
    $$
    This determinant represents the volume of a parallelepiped with one edge as the unit vector $\mathbf{k}$, which is numerically equal to the area of the parallelogram formed by $\mathbf{a}$ and $\mathbf{b}$.

    ![](https://pic1.imgdb.cn/item/67f5e87088c538a9b5c6f714.png)

- **Direction of Cross Product**: The direction of the cross product is determined by the right-hand rule. If you align your right hand so that your fingers point in the direction of $\mathbf{a}$ and then curl them towards $\mathbf{b}$, your thumb will point in the direction

![Capture_20250409_115421.jpg](https://pic1.imgdb.cn/item/67f5efe088c538a9b5c711df.jpg)
![](https://pic1.imgdb.cn/item/67f5f02e88c538a9b5c7133f.png)
还有一个重要性质就是行列式为0（**判断四点是否共面**）

