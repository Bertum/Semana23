import QtQuick 2.1
import Qt3D.Core 2.0
import Qt3D.Render 2.9
import Qt3D.Input 2.0
import Qt3D.Extras 2.9

Entity {
    id: park

    components: [ parkMesh, parkMaterial ]

    Mesh {
        id: parkMesh
        source: "/paque.blend"
    }

    MetalRoughMaterial {
        id: parkMaterial
        baseColor: Qt.rgba( 0.8, 0.0, 0.0, 1.0 )
        metalness: 0.2
        roughness: 0.5
    }
}
