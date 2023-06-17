#version 330
out vec4 FragColor;

in vec4 fragColor;
in vec3 Normal;  
in vec3 FragPos;
in vec3 TexCoords;
  
uniform vec3 lightPos; 
uniform vec3 viewPos; 
uniform vec3 lightColor;
uniform vec3 objectColor;

uniform bool isLighting;
uniform bool isTexture;
uniform bool isNormalMap;

uniform samplerCube cubemap;

void main()
{
    if (isTexture) {
        FragColor = texture(cubemap, TexCoords);
    }

    if (isLighting) {
        float ambientStrength = 0.1;
        vec3 ambient = ambientStrength * lightColor;

        // diffuse
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - FragPos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * lightColor;

        float constant = 1.0;
        float linear = 0.09;
        float quadratic = 0.032;
        float distance = length(lightPos - FragPos);
        float attenuation = 1.0 / (constant + linear * distance + quadratic * distance * distance);

        // specular
        float specularStrength = 0.5;
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
        vec3 specular = specularStrength * spec * lightColor;

        if (isTexture) {
            vec3 result = (ambient + diffuse + specular);
            FragColor = (vec4(result, 1.0) * texture(cubemap, TexCoords)) * attenuation;
        } else {
            vec3 result = ((ambient + diffuse + specular) * fragColor.xyz) * attenuation;
            FragColor = vec4(result, 1.0);
        }
    }

    if (!isLighting && !isTexture) {
        FragColor = fragColor;
    }
}