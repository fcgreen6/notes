// --Three.js Notes Main Script--
// Author: Fletcher Green

//------------------------------------------------------------------------
// Section: Initialization
//------------------------------------------------------------------------

// --Loading Three.js--
// Description: Three.js can be loaded with this import statement.
import * as THREE from 'three';

// --Creating a Renderer--
// Description: To create a visualization, three items are needed: a renderer, a scene, and scene meshes.
//              A basic WebGL renderer will be used to create this visualization with the same width as the screen
//              and a vertical height of 100 pixels.
const testOneRenderer = new THREE.WebGLRenderer();
testOneRenderer.setSize(window.innerWidth, 100);
document.getElementById("test1").innerHTML = "<h3>Test 1</h3>"; // Modify the inner HTML of the first test div.
document.getElementById("test1").appendChild(testOneRenderer.domElement); // Append the renderer HTML element to the inner HTML.

// --Creating a Scene--
// Description: There is not much initialization involved when creating a scene. Meshes will be added to the scene later.
const testOneScene = new THREE.Scene();

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
testOneCamera.position.z = 1; // Move the camera away from the x - y plane so that a shape can be seen.

//------------------------------------------------------------------------
// Section: Meshes
//------------------------------------------------------------------------

// --Meshes--
// Description: Creating a mesh requires a geometry to define its shape and a material to define its texture.
const testOneGeo = new THREE.PlaneGeometry(window.innerWidth / 2, 50);
const testOneMaterial = new THREE.MeshBasicMaterial({color: 0x00ff00});
const testOnePlane = new THREE.Mesh(testOneGeo, testOneMaterial); // By default this is centered at the orgin.

// Add the geometry to the scene.
testOneScene.add(testOnePlane);
testOneRenderer.render(testOneScene, testOneCamera); // Render the scene using the orthographic camera.