#type vertex
#version 460 core

layout (location = 0) in vec2 a_Position;
layout (location = 1) in vec2 a_TexCoord;
layout (location = 2) in int a_TexIndex;

uniform mat4 u_ViewProjection;

out vec2 v_TexCoord;
out flat int v_TexIndex;

void main()
{
	gl_Position = u_ViewProjection * vec4(a_Position, 0.0, 1.0);
	v_TexCoord = a_TexCoord;
	v_TexIndex = a_TexIndex;
};

#type fragment
#version 460 core

in vec2 v_TexCoord;
in flat int v_TexIndex;

layout(location = 0) out vec4 color;

uniform sampler2D u_Textures[32];

void main()
{
	color = texture(u_Textures[v_TexIndex], v_TexCoord);
	//color = texture(u_Textures[0], vec2(0.0, 0.0));
	// if(v_TexIndex == 0){
	// 	color = vec4(1.0,0.0,1.0,1.0);
	// }
};