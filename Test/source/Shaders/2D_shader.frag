#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    vec4 TextureColor = texture(ourTexture , vec2(TexCoord.x, TexCoord.y));

    if(TextureColor.a < 0.1)
        discard;
    FragColor = TextureColor;

}