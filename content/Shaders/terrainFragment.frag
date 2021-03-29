#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in float HeightPoint;

uniform sampler2D sandTexture;
uniform sampler2D grassTexture;
uniform sampler2D snowTexture;
uniform sampler2D detailMap;

uniform float sandHeight;
uniform float grassHeight;
uniform float snowHeight;

void main(){
    vec4 sand = texture(sandTexture, TexCoord);
    vec4 grass = texture(grassTexture, TexCoord);
    vec4 snow = texture(snowTexture, TexCoord);
    vec4 detail = texture(detailMap, TexCoord);
    //FragColor = vec4(0.8,0,0,0);
    if(HeightPoint > snowHeight){

        FragColor = snow;
    }
    else if(HeightPoint > grassHeight){
        float blend = (HeightPoint - grassHeight) / (snowHeight - grassHeight);
        FragColor = mix(grass,snow,blend);
    }
    else if(HeightPoint > sandHeight){
        float blend = (HeightPoint - sandHeight) / (grassHeight - sandHeight);
        FragColor = mix(sand,grass,blend);
    }
    else{
        FragColor = sand;
    }
    FragColor = FragColor * detail;
}