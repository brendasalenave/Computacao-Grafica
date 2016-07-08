#include "draw.h"
#include <QOpenGLFunctions_1_1>


Draw::Draw()
{

}

void Draw::cube_(float x, float y, float z, float s){

    glBegin(GL_QUADS);                  // Draw The Cube Using quads
    glTranslatef(x,y,z);

      glColor3f(1.0f,1.0f,0.0f);        // Color Yellow
      glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
      glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
      glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
      glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)

      glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
      glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
      glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
      glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)

      glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
      glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
      glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
      glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)

      glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
      glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
      glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
      glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)

      glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
      glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
      glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
      glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)

      glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
      glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
      glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
      glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)
    glEnd();            // End Drawing The Cube


}
