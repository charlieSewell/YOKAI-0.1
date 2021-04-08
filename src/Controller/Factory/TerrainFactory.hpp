
#include <vector>
#include <glm/gtc/noise.hpp>
#include <glm/gtx/normal.hpp>
#include <math.h>
#include "View/Renderer/DataTypes.hpp"
#include "Model/Chunk.hpp"
#include "Controller/LuaManager.hpp"
#include "Controller/Physics/PhysicsManager.hpp"

/**
 * @class TerrainFactory
 * @brief Responsible for the creation of terrain
 */
class TerrainFactory 
{
  public:
    /*!
     * @brief Singleton Pattern for a single instance of the class
     * @return instance
     */
    static TerrainFactory & getInstance();

    /*!
     * @brief Initialises the factory for terrain geenration
     */
    void Init();

    /*!
     * @brief Sets up the chunk to be used for terrain generation
     * @param unsigned int - xStart
     * @param unsigned int - zStart
     * @param unsigned int - size
     * @return Chunk
     */
    Chunk SetupChunk(unsigned int xStart,unsigned int zStart,int size);

    /*!
     * @brief Getter for the size of the terrain
     * @return terrainSize
     */
    int getTerrainSize(){return terrainSize;}

  private:
    /*!
     * @brief Constructor
     */
    TerrainFactory() = default;

    /*!
     * @brief Deconstructor
     */
    ~TerrainFactory() = default;

    /*!
     * @brief Copy constructor
     */
    TerrainFactory(const TerrainFactory &) = delete;

    /*!
     * @brief Assignment operator
     */
    TerrainFactory &operator =(const TerrainFactory &);

    /*!
     * @brief Generates a flat terrain map
     * @param Vector<Vertex> - &terrain
     * @param unsigned int - xStart
     * @param unsigned int - zStart
     * @param int - xSize
     * @param int - zSize
     */
    void GenerateFlatMap(std::vector<Vertex> &terrain,unsigned int xStart,unsigned int zStart,int xSize, int zSize);

    /*!
     * @brief Generates terrain indices
     * @param Vector<unsigned int> - &terrain
     * @param int - xSize
     * @param int - zSize
     */
    void GenerateTerrainIndices(std::vector<unsigned int> &terrain,int xSize, int zSize);

    /*!
     * @brief Generates texture coordinates
     * @param Vector<Vertex> - &terrain
     * @param int - xSize
     * @param int - zSize
     */
    void GenerateTexCoords(std::vector<Vertex> &terrain,int xSize, int zSize);

    /*!
     * @brief Generates normals for terrain
     * @param Vector<Vertex> - &terrain
     * @param Vector<unsigned int> - &indices
     */
    void GenerateNormals(std::vector<Vertex> &terrain, std::vector<unsigned int> &indices);

    /*!
     * @brief Generates terrain with perlin map algorithm
     * @param int - xSize
     * @param int - ySize
     */
    void GeneratePerlinMap(int xSize,int ySize);

    /*!
     * @brief Loads terrain data from external height map
     * @param string - filename
     */
    void LoadHeightMap(std::string filename);

    /*!
     * @brief Loads terrain data from external height map
     * @param int - x
     * @param int - z
     * @return float height
     */
    float heightAt(int x,int z);

    /// 2D vector of floats for terrain height values
    std::vector<std::vector<float>> heightVals = {};

    /// Vector of Texture smart pointers for terrain textures
    std::vector<std::shared_ptr<Texture>> terrainTextures;

    /// String for the path to specified texture
    std::string sandTexture;

    /// String for the path to specified texture
    std::string snowTexture;

    /// String for the path to specified texture
    std::string grassTexture;

    /// String for the path to detail map
    std::string detailTexture;

    /// Integer values for the various heights that textures change on the terrain
    int sandHeight,grassHeight,snowHeight;

    /// Integer size for the terrain
    int terrainSize;

    /// String for the path to the heightmap
    std::string mapPath;

    /// Boolean check if an external heightmap is being used
    bool useHeightMap = false;

};

