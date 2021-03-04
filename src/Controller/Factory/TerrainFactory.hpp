//
// Created by Charlie Sewell on 4/03/2021.
//

#ifndef ICT397_GAME_ENGINE_TERRAINFACTORY_HPP
#define ICT397_GAME_ENGINE_TERRAINFACTORY_HPP

class TerrainFactory {
  public:
    static TerrainFactory & getInstance();
  private:
    TerrainFactory() = default;
    ~TerrainFactory() = default;
    TerrainFactory(const TerrainFactory &) = delete;
    TerrainFactory &operator =(const TerrainFactory &);
};

#endif // ICT397_GAME_ENGINE_TERRAINFACTORY_HPP
