uniform vec2 u_resolution; // 画面の解像度(width,height)
uniform float u_time;      // 起動してからの経過時間(秒)

void main() {
    //画面の解像度から、0.0〜1.0に正規化する
    vec2 st = gl_FragCoord.xy / u_resolution;
    // 画面の中央をy軸の中心に
    st.y -= 0.5;
    // Sin波で濃淡をつける
    st.y += sin(st.x * 10.0 + u_time) * 0.2;
    // 1から引いて、乗算する
    vec3 color = vec3(1.0 - pow(abs(st.y), 0.2));
    gl_FragColor = vec4(color, 1.0);
}