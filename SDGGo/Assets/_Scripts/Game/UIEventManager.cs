﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

    public class UIEventManager : MonoBehaviour
    {

        void Start() {
        }

        void Update() {
            if (Input.GetMouseButtonDown(1)) {
                BackHome();
            }
        }

        public void BackHome() {
            SceneManager.LoadScene("Menu");
        }
    }