// C++ source file - (C) 2003 Robert Osfield, released under the OSGPL.
// (C) 2005 Mike Weiblen http://mew.cx/ released under the OSGPL.
// Simple example using GLUT to create an OpenGL window and OSG for rendering.
// Derived from osgGLUTsimple.cpp and osgkeyboardmouse.cpp

#include <osgViewer/SimpleViewer>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>

class QWidget;
#include <qtimer.h>
#include <qgl.h>
#include <qapplication.h>

#include <iostream>

class GraphicsWindowQT : public QGLWidget, virtual public osgViewer::GraphicsWindow
{
public:

    GraphicsWindowQT( QWidget * parent = 0, const char * name = 0, const QGLWidget * shareWidget = 0, WFlags f = 0 );
    virtual ~GraphicsWindowQT() {}

protected:

    virtual void resizeGL( int width, int height );
    virtual void keyPressEvent( QKeyEvent* event );
    virtual void keyReleaseEvent( QKeyEvent* event );
    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent* event );
    virtual void mouseMoveEvent( QMouseEvent* event );

    QTimer _timer;
};

GraphicsWindowQT::GraphicsWindowQT( QWidget * parent, const char * name, const QGLWidget * shareWidget, WFlags f):
    QGLWidget(parent, name, shareWidget, f)
{
    connect(&_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    _timer.start(10);
}

void GraphicsWindowQT::resizeGL( int width, int height )
{
    getEventQueue()->windowResize(0, 0, width, height );
}

void GraphicsWindowQT::keyPressEvent( QKeyEvent* event )
{
    getEventQueue()->keyPress( (osgGA::GUIEventAdapter::KeySymbol) event->ascii() );
}

void GraphicsWindowQT::keyReleaseEvent( QKeyEvent* event )
{
    getEventQueue()->keyRelease( (osgGA::GUIEventAdapter::KeySymbol) event->ascii() );
}

void GraphicsWindowQT::mousePressEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
    getEventQueue()->mouseButtonPress(event->x(), event->y(), button);
}

void GraphicsWindowQT::mouseReleaseEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
    getEventQueue()->mouseButtonRelease(event->x(), event->y(), button);
}

void GraphicsWindowQT::mouseMoveEvent( QMouseEvent* event )
{
    getEventQueue()->mouseMotion(event->x(), event->y());
}


class SimpleViewerQT : public osgViewer::SimpleViewer, public GraphicsWindowQT
{
    public:

        SimpleViewerQT(QWidget * parent = 0, const char * name = 0, const QGLWidget * shareWidget = 0, WFlags f = 0):
            GraphicsWindowQT( parent, name, shareWidget, f )
            {}

        virtual void initializeGL()
        {
            QGLWidget::initializeGL();    
        }

        virtual void paintGL()
        {
            frame();
        }

};

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    
    if (argc<2)
    {
        std::cout << argv[0] <<": requires filename argument." << std::endl;
        return 1;
    }

    // load the scene.
    osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(argv[1]);
    if (!loadedModel)
    {
        std::cout << argv[0] <<": No data loaded." << std::endl;
        return 1;
    }


    SimpleViewerQT* viewerWindow = new SimpleViewerQT;

    viewerWindow->setSceneData(loadedModel.get());
    viewerWindow->setCameraManipulator(new osgGA::TrackballManipulator);

    viewerWindow->show();
    a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
   
    return a.exec();
}

/*EOF*/
