#include "mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
    //Control number of vertices to draw
    m_drawCount = numVertices;

    //Allocate the number of objects arrays
    glGenVertexArrays(1, &m_vertexArrayObject);

    //bind vertex array
    glBindVertexArray(m_vertexArrayObject);

    //Generate Buffers, bind it and pass data (ie.: from RAM to GPU)
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    //Set array attribute
    glEnableVertexAttribArray(0);

    //define an array of generic vertex attribute data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);


    glBindVertexArray(0);

}

Mesh::~Mesh()
{
    //Delete the vertex array object at end
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw()
{
    glBindVertexArray(m_vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

    glBindVertexArray(0);
}
