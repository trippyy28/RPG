#include "TileMap.h"

bool TileMap::load(const std::string &tileset, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height)
{
    // Load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // Resize the vertex array to fit the level size and initialize it as Quads
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // Populate the vertex array with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            int tileNumber = tiles[i + j * width]; // Get the current tile number

            // Find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // Get a pointer to the current tile's quad
            sf::Vertex *quad = &m_vertices[(i + j * width) * 4];

            // Define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // Set the texture coordinates of the quad
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }

    return true;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform(); // apply the transform
    states.texture = &m_tileset;        // apply the tileset texture
    target.draw(m_vertices, states);    // draw the vertex array
}
