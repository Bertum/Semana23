#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <Qt3DRender>
#include <Qt3DCore>
#include <QDebug>
#include <Qt3DExtras>
#include <QSceneLoader>

Qt3DCore::QEntity *createScene()
{
    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    // Create scene
    Qt3DRender::QSceneLoader *sceneLoader = new Qt3DRender::QSceneLoader(rootEntity);
    sceneLoader->setSource(QUrl(QStringLiteral("qrc:/parque.obj")));

    //Qt3DRender::QSpotLight *light = new Qt3DRender::QSpotLight(rootEntity);
    //light->setIntensity(0.1f);

    rootEntity->addComponent(sceneLoader);

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
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // For camera controls
    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(scene);
    camController->setLinearSpeed(50.0f);
    camController->setLookSpeed(180.0f);
    camController->setCamera(camera);

    //Set scene to view
    view.setRootEntity(scene);
    view.show();

    app.exec();
}
