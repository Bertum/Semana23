#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <Qt3DRender>
#include <Qt3DCore>
#include <QDebug>
#include <Qt3DExtras>

void createLawMan(Qt3DCore::QEntity *rootEntity){
    // Material
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);

    // LawMan entity
    Qt3DCore::QEntity *lawManEntity = new Qt3DCore::QEntity(rootEntity);

    // Import model
    Qt3DRender::QMesh *mesh = new Qt3DRender::QMesh();
    mesh->setSource(QUrl(QStringLiteral("qrc:/objs/lawMan.obj")));

    lawManEntity->addComponent(mesh);
    lawManEntity->addComponent(material);
}

Qt3DCore::QEntity *createScene()
{
    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    // Create the law man
    createLawMan(rootEntity);

    return rootEntity;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Qt3DExtras::Qt3DWindow view;

    // Create the scene
    Qt3DCore::QEntity *scene = createScene();

    // Camera
    Qt3DRender::QCamera *camera = view.camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // For camera controls
    Qt3DExtras::QFirstPersonCameraController  *camController = new Qt3DExtras::QFirstPersonCameraController (scene);
    camController->setLinearSpeed( 50.0f );
    camController->setLookSpeed( 180.0f );
    camController->setCamera(camera);

    //Set scene to view
    view.setRootEntity(scene);
    view.show();

    app.exec();
}
