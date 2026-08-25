NOTE
1. glfwInit & glfwCreateWindow = hanya melakukan inisialisasi window serta ukuran size nya
2. gladLoadGLLoader = menyambungkan kode program c++ saya dengan driver VGA di device laptop saya ini
3. glfwWindowShouldClose = render loop
4. glfwTerminate = kalo jendelanya ditutup, bersihkan memori & matikan program

CARA KERJA RENDER
1. shaderProgram yang mengatur shader (vertices, fragment) untuk pewarnaan...dan terdapat variable pada fragment / vertices yang dapat diambil lokasinya dengan passing shaderProgram lalu nama variable nya
2. VAO adalah largest buffer yang menampung VBO (titik sudut) & EBO (urutan render sudut)