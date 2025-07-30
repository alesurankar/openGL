#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec3 color;
// Inputs the texture coordinates from the Vertex Shader
in vec2 texCoord;

// Gets the Texture Unit from the main function
uniform sampler2D tex0;


//void main()
//{
//	FragColor = texture(tex0, texCoord);
//}

void main()
{
    vec4 texColor = texture(tex0, texCoord);
    FragColor = texColor * vec4(color, 1.0);
}

//greyish color
//void main()
//{
//    vec4 texColor = texture(tex0, texCoord);
//    float gray = dot(texColor.rgb, vec3(0.299, 0.587, 0.114));
//    FragColor = vec4(vec3(gray), texColor.a);
//}

//Flip
//void main()
//{
//    vec2 flippedTexCoord = vec2(1.0 - texCoord.x, texCoord.y);
//    FragColor = texture(tex0, flippedTexCoord);
//}

//offset
//void main()
//{
//    vec2 offsetCoord = texCoord + vec2(0.1, 0.0);
//    FragColor = texture(tex0, offsetCoord);
//}

//Bind with a solid color
//void main()
//{
//    vec4 texColor = texture(tex0, texCoord);
//    vec4 red = vec4(1.0, 0.0, 0.0, 1.0);
//    FragColor = mix(texColor, red, 0.5); // 50% blend
//}