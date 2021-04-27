#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in float visibility;
uniform sampler2D texture_diffuse1;
uniform vec3 skyColor;
void main()
{
    vec4 texColor = texture(texture_diffuse1, TexCoords);

    if(texColor.a < 0.1)
        discard;
    //FragColor = vec4(0.8,0,0,0);
    FragColor = texColor;
    FragColor = mix(vec4(skyColor,1.0),FragColor,visibility);
}