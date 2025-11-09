#include "PostEffect.h"

#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>

void PostEffect::applyShader(const sf::Shader& shader, sf::RenderTarget& output)
{
	sf::Vector2f outputSize = static_cast<sf::Vector2f>(output.getSize());

	sf::VertexArray verticles(sf::TrianglesStrip, 4);
	verticles[0] = sf::Vertex(sf::Vector2f(0, 0), sf::Vector2f(0, 1));
	verticles[1] = sf::Vertex(sf::Vector2f(outputSize.x, 0), sf::Vector2f(1, 1));
	verticles[2] = sf::Vertex(sf::Vector2f(0, outputSize.y), sf::Vector2f(0, 0));
	verticles[3] = sf::Vertex(sf::Vector2f(outputSize), sf::Vector2f(1, 0));

	sf::RenderStates states; 
	states.shader = &shader;
	states.blendMode = sf::BlendNone;

	output.draw(verticles, states);
}

PostEffect::~PostEffect()
{
}

bool PostEffect::isSupported()
{
	return sf::Shader::isAvailable();
}

