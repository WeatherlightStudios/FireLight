#version 330 core

out vec4 FragColor;

in vec2 TexCoord;
in float textureID;

uniform sampler2D textures[32];

void main()
{
	int tIDs = int(textureID - 0.5f);
    vec4 TextureColor = texture(textures[tIDs] , vec2(TexCoord.x, TexCoord.y));

    if(TextureColor.a < 0.1)
        discard;
    FragColor = TextureColor;

}