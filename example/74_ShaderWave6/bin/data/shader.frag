uniform vec2 u_resolution; // 画面の解像度(width,height)
uniform float u_time;      // 起動してからの経過時間(秒)
const int NUM = 20;        // 波の数
uniform float freq[20];   // oFから受けとる波の配列

void main() {
    vec3 color;
    // 波の数だけくりかえす
    for (int i = 0; i < NUM; i++) {
        //画面の解像度から、0.0〜1.0に正規化する
        vec2 st = gl_FragCoord.xy / u_resolution;
        // 画面の中央をy軸の中心に
        st.y -= 0.5;
        // Sin波で濃淡をつける + 時間による変化
        st.y += sin(st.x * freq[i] + u_time) * 0.2 * sin(u_time * freq[i] * 0.1);
        // 1から引いて、乗算する
        color += vec3(1.0 - pow(abs(st.y), 0.75/float(NUM)));
        // 色を設定
        gl_FragColor = vec4(color.r * 0.2, color.g * 0.5, color.b * 1.0, 1.0);
    }
}