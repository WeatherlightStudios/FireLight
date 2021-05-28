[Material]
{
    _Color : ("MyColor", vec3);
    _noiseOffset : ("NoiseOffset", vec2);
    _Color : ("MyColor", float);
    _Color : ("MyColor", Texture2D);
    _Color : ("MyColor", vec3);
    _Color : ("MyColor", vec3);
}

[Vertex]
{
    #version 330 core

    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;

    uniform mat4 model;
    uniform mat4 projection;

    out vec3 vColor;

    void main()
    {
        vColor = aColor;
        
        gl_Position = projection * model * vec4(aPos, 1.0f);
    }
}

[Fragment]
{
    #version 330 core
    out vec4 FragColor;
    in vec3 vColor;
    void main()
    {
        FragColor = vec4(vColor, 1.0);
    }

}