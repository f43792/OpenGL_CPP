#ifndef MESH_H
#define MESH_H

#include<glm/glm.hpp>

class Vertex
{
    public:
        Vertex(const glm::vec3& pos){
            this->pos = pos;
        }
    protected:
    private:
        glm::vec3 pos;
};


class Mesh
{
    public:
        Mesh();
        virtual ~Mesh();

        void Draw();

    protected:
    private:
        Mesh(const Mesh& other);
        Mesh& operator=(const Mesh& other);
};

#endif // MESH_H
