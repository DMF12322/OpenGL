#version 330 core							 
in vec4 vertexColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform sampler2D ourFace;

//uniform vec4 ourColor;//		 
out vec4 FragColor;                          
void main(){								 
	//FragColor = vertexColor;
	FragColor = texture(ourTexture, TexCoord) * texture(ourFace, TexCoord);
}