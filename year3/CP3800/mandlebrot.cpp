#include <GL/glut.h>

void drawMB( const int w, const int h )
{
    const double minReal = -2.0;
    const double maxReal = 0.5;
    const double minImaginary = -1.25;
    const double maxImaginary = 1.25;
    const int maxIt = 2000;     // Max iterations for the set computations

    const double Re_factor = ( maxReal - minReal ) / ( w - 1 );
    const double Im_factor = ( maxImaginary - minImaginary ) / ( h - 1 );

    glColor4f( 0.0, 0.0, 0.0, 0.0 );//set pixel color 0=black 1=white
    glPointSize( 1 );
    glBegin( GL_POINTS );

    for( int y = 0; y < h; ++y )
    {
        const double c_im = maxImaginary - y*Im_factor;

        for( int x = 0; x < w; ++x )
        {
            const double c_re = minReal + x*Re_factor;
            double Z_re = c_re, Z_im = c_im;
            bool isInside = true;

            for( int n = 0; n < maxIt; ++n )
            {
                double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;

                if( Z_re2 + Z_im2 > 4 )
                {
                    isInside = false;
                    break;
                }
                Z_im = 2 * Z_re*Z_im + c_im;
                Z_re = Z_re2 - Z_im2 + c_re;
            }
            if( isInside )
            {
                glVertex2i( x, y );
            }
        }
    }

    glEnd();
}

void display( void )
{
    glClearColor( 1.0, 1.0, 1.0, 1.0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    const int w = glutGet( GLUT_WINDOW_WIDTH );
    const int h = glutGet( GLUT_WINDOW_HEIGHT );
    glOrtho( 0, w, h, 0, -1, 1 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    drawMB( w, h );

    glutSwapBuffers();
}

int main( int argc, char** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 512, 512 );
    glutInitWindowPosition( 100, 100 );
    glutCreateWindow( "Mandelbrot Set" );
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}