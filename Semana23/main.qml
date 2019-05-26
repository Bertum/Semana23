import QtQuick 2.1
import Qt3D.Core 2.0
import Qt3D.Render 2.9
import Qt3D.Input 2.0
import Qt3D.Extras 2.9

Entity {
    id: root
    objectName: "root"

    // Use the renderer configuration specified in ForwardRenderer.qml
    // and render from the mainCamera
    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                camera: mainCamera
            }
        },
        // Event Source will be set by the Qt3DQuickWindow
        InputSettings { }
    ]

    BasicCamera {
        id: mainCamera
        position: Qt.vector3d( -5.17253, 2.95727, 6.65948 )
        viewCenter: Qt.vector3d( 6.73978, -2.50545, -10.6525 )
    }

    FirstPersonCameraController { camera: mainCamera }

    Mesh{
        id:parkMesh
        source: "parque.obj"
    }

    Entity{
        id:park
        components: [parkMesh, parkMaterial]

        TexturedMetalRoughMaterial {
            id: parkMaterial
            baseColor:  TextureLoader {
                source: "assets/textures/aluminium_random_brushed/aluminium_random_brushed_basecolor.png"
                format: Texture.SRGB8_Alpha8
                generateMipMaps: true
            }
            metalness: TextureLoader { source: "assets/textures/aluminium_random_brushed/aluminium_random_brushed_metallic.png"; generateMipMaps: true }
            roughness: TextureLoader { source: "assets/textures/aluminium_random_brushed/aluminium_random_brushed_roughness.png"; generateMipMaps: true}
            normal: TextureLoader { source: "assets/textures/aluminium_random_brushed/aluminium_random_brushed_normal.png"; generateMipMaps: true }
            ambientOcclusion: TextureLoader { source: "assets/textures/no-ao.png" }
        }

    }

}
