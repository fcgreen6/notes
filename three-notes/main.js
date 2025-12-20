// --Three.js Notes Main Script--
// Author: Fletcher Green

//------------------------------------------------------------------------
// Section: Initialization
//------------------------------------------------------------------------

// --Loading Three.js--
// Description: Three.js can be loaded with this import statement.
import * as THREE from 'three';

// --Loading Shaders--
// Description: Shaders can be specified within their own files. However, they must be loaded into JavaScript strings
//              for use.
const testTwoVertex = 
`varying vec3 vWorldPos;

void main () {
    vWorldPos = (modelMatrix * vec4(position, 1.0)).xyz;
    gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0);
}`;

const testTwoFragment = 
`varying vec3 vWorldPos;

void main() {
    gl_FragColor = vec4((1.0 / 100.0) * (vWorldPos.z + 50.0), 0, 0, 1);
}`;

// --Creating a Renderer--
// Description: To create a visualization, three items are needed: a renderer, a scene, and scene meshes.
//              A basic WebGL renderer will be used to create this visualization with the same width as the screen
//              and a vertical height of 100 pixels.
const testOneRenderer = new THREE.WebGLRenderer();
testOneRenderer.setSize(window.innerWidth, 100);
document.getElementById("test1").innerHTML = "<h3>Test 1</h3>"; // Modify the inner HTML of the first test div.
document.getElementById("test1").appendChild(testOneRenderer.domElement); // Append the renderer HTML element to the inner HTML.

const testTwoRenderer = new THREE.WebGLRenderer();
testTwoRenderer.setSize(window.innerWidth, 100);
document.getElementById("test2").innerHTML = "<h3>Test 2</h3>";
document.getElementById("test2").appendChild(testTwoRenderer.domElement);

// --Creating a Scene--
// Description: There is not much initialization involved when creating a scene. Meshes will be added to the scene later.
const testOneScene = new THREE.Scene();

const testTwoScene = new THREE.Scene();

//------------------------------------------------------------------------
// Section: Cameras
//------------------------------------------------------------------------

// --Orthographic Camera--
// Description: A rectangular camera in which viewed items are not distorted by perspective. Parallel lines
//              do not converge at a single point, meaning that objects have the same size regardless of their diatance
//              from the camera. The z-axis can be used for layering.
// Camera Frustums: These can be thought of as the bounds of the camera. The first four parameters represent the x or y position
//                  of the left, right, top, and bottom frustums respectivley.
// Near Plane: A plane parallel to the view of the camera in which items in front of it will not be loaded.
// Far Plane: A plane parallel to the view of the camera in which items behind it will not be loaded.
const testOneCamera = new THREE.OrthographicCamera(window.innerWidth / -2, window.innerWidth / 2, 50, -50, 0.1, 1000);
testOneCamera.position.z = 100; // Move the camera away from the x - y plane so that a shape can be seen.

//------------------------------------------------------------------------
// Section: Meshes
//------------------------------------------------------------------------

// --Meshes--
// Description: Creating a mesh requires a geometry to define its shape and a material to define its texture.
const testOneGeo = new THREE.PlaneGeometry(window.innerWidth / 2, 50);
const testOneMaterial = new THREE.MeshBasicMaterial({color: 0x00ff00});
const testOnePlane = new THREE.Mesh(testOneGeo, testOneMaterial); // By default this is centered at the orgin.

// --Using Shader Files--
// Description: Custom GLSL shader files can be attached to a shader material as shown below.
const testTwoGeo = new THREE.BoxGeometry(50, 90, 90);
const testTwoMaterial = new THREE.ShaderMaterial({
    fragmentShader: testTwoFragment,
    vertexShader: testTwoVertex
});
const testTwoBox = new THREE.Mesh(testTwoGeo, testTwoMaterial); // By default this is centered at the orgin.

// Add geometry to scene one.
testOneScene.add(testOnePlane);
testOneRenderer.render(testOneScene, testOneCamera); // Render the scene using the orthographic camera.

// Add geometry to scene two.
testTwoScene.add(testTwoBox);
testTwoRenderer.render(testTwoScene, testOneCamera);

//------------------------------------------------------------------------
// Section: Animations
//------------------------------------------------------------------------

// --Animation Loops--
// Description: Animation loops can be set for an individual renderer. The function code is called every
//              frame.
testTwoRenderer.setAnimationLoop(TestTwoAnimation);
const testTwoClock = new THREE.Clock(); // Create a clock object to get elapsed time.
function TestTwoAnimation() {
    testTwoBox.rotation.y = Math.PI * testTwoClock.getElapsedTime(); // Rotate 180 degrees every second.
    testTwoRenderer.render(testTwoScene, testOneCamera);
}