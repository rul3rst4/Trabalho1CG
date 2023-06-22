#version 330
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec3 TexCoords;
    vec3 TangentLightPos;
    vec3 TangentViewPos;
    vec3 TangentFragPos;
    vec3 Normal;
} fs_in;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;

uniform bool isLighting;
uniform bool isTexture;
uniform bool isNormalMap;

uniform samplerCube cubemap;
uniform samplerCube normalMap;

void main()
{
    vec3 color = vec3(1.0);
    vec3 norm = normalize(fs_in.Normal);
    vec3 lightDir = vec3(1.0);
    vec3 viewDir = vec3(1.0);

    if (isTexture) {
        color = texture(cubemap, fs_in.TexCoords).rgb;

        lightDir = normalize(lightPos - fs_in.FragPos);
        viewDir = normalize(viewPos - fs_in.FragPos);
    }

    if (isNormalMap) {
        norm = texture(normalMap, fs_in.TexCoords).rgb;
        norm = normalize(norm * 2.0 - 1.0);

        lightDir = normalize(fs_in.TangentLightPos - fs_in.TangentFragPos);
        viewDir = normalize(fs_in.TangentViewPos - fs_in.TangentFragPos);
    }

    if (isLighting) {
        // ambient
        float ambientStrength = 0.1;
        vec3 ambient = ambientStrength * color;

        // diffuse
        float diff = max(dot(lightDir, norm), 0.0);
        vec3 diffuse = diff * color;

        // specular
        float specularStrength = 0.2;
        vec3 reflectDir = reflect(-lightDir, norm);
        vec3 halfwayDir = normalize(lightDir + viewDir);
        float spec = pow(max(dot(norm, halfwayDir), 0.0), 32.0);
        vec3 specular = specularStrength * spec * color;

        float constant = 1.0;
        float linear = 0.09;
        float quadratic = 0.032;
        float distance = length(lightPos - fs_in.FragPos);
        float attenuation = 1.0 / (constant + linear * distance + quadratic * distance * distance);

        vec3 result = (ambient + diffuse + specular) * attenuation;
        FragColor = vec4(result, 1.0);
    } else if (!isTexture && !isNormalMap) {
        FragColor = vec4(fs_in.FragPos, 1.0);
    } else {
        FragColor = vec4(color, 1.0);
    }
}