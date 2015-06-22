uniform vec2 u_resolution; // 画面の解像度(width,height)
uniform float u_time;      // 起動してからの経過時間(秒)

void main() {
    float red = abs(sin(u_time * 3.0));
    float green = abs(sin(u_time * 4.0));
    float blue = abs(sin(u_time * 5.0));
    gl_FragColor = vec4(red, green, blue, 1.0);
}