# 🎮 Wolf3D

Un moteur de jeu 3D à la première personne implémenté en **C** utilisant le **raycasting**, inspiré du classique jeu Wolf3D.

## 📋 Table des matières

- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Architecture](#architecture)
- [Contrôles](#contrôles)
- [Paramètres](#paramètres)

## 🎯 Fonctionnalités

### Gameplay
- **Moteur 3D par raycasting** - Rendu en temps réel avec détection des collisions
- **Minimap** - Navigation avec vue de dessus
- **Armes** - Système d'armes avec animations
- **Projectiles et effets** - Systèmes de particules pour les dash
- **Animations** - Animation des personnages et mouvements fluides

### Système de Jeu
- **Menu principal** - Navigation intuitive avec boutons
- **Paramètres avancés** - Configuration complète du jeu
  - Vidéo (résolution, mode plein écran, FPS)
  - Audio (volume général, musique, effets sonores)
  - Contrôles (touches personnalisables)
  - Jeu (sensibilité, etc.)
- **Sauvegarde/Chargement** - Persistence de la progression
- **HUD** - Affichage des informations de jeu en temps réel
- **Torche** - Système d'éclairage dynamique

### Système Audio-Visuel
- **Musique de thème** - Bande sonore immersive
- **Effets sonores** - Bruitages variés
- **Système de volume modulable** - Contrôle audio granulaire
- **Assets personnalisés** - Sprites et textures optimisés

## 🚀 Installation

### Prérequis
- GCC compiler
- CSFML (C-Bindings for SFML)
- Make

### Sur Linux (Ubuntu/Debian)
```bash
sudo apt-get install libcsfml-dev build-essential
```

### Compilation
```bash
cd wolf3d
make
```

Pour une compilation optimisée :
```bash
make opti
```

## 🎮 Utilisation

### Lancer le jeu
```bash
./wolf3d
```

### Exécuter les tests
```bash
make unit_tests
make tests_run
```

### Vérification de fuite mémoire
```bash
make val_run
```

## 🏗️ Architecture

### Structure du Projet

```
src/
├── mainloop/          # Boucle de jeu principale
├── main_menu/         # Gestion du menu principal
├── main_screen/       # Écran de jeu
├── init_struct/       # Initialisation des structures
├── settings/          # Système de paramètres
├── video_settings/    # Configuration vidéo
├── event_settings/    # Gestion des événements des paramètres
└── save_load/         # Sauvegarde et chargement
```

### Modules Clés

| Module | Description |
|--------|-------------|
| **raycast_algo** | Algorithme de raycasting pour le rendu 3D |
| **ray_rendering** | Rendu des rayons et walls |
| **display_minimap** | Affichage de la minimap |
| **player_moves** | Déplacement et collision du joueur |
| **wall_rendering** | Rendu des murs |
| **game_event** | Gestion des événements du jeu |
| **audio_controls** | Gestion audio |
| **video_display_mode** | Gestion des modes d'affichage |

## 🎮 Contrôles

| Action | Touche |
|--------|--------|
| Avancer | W ou Flèche Haut |
| Reculer | S ou Flèche Bas |
| Gauche | A ou Flèche Gauche |
| Droite | D ou Flèche Droite |
| Dash | Espace |
| Paramètres | Esc |
| Plein écran | F11 |

*Les contrôles peuvent être personnalisés dans le menu Paramètres*

## ⚙️ Paramètres

### Vidéo
- Résolution (windowed/fullscreen/windowed fullscreen)
- Limite FPS (30, 60, 120, 144 FPS)
- V-Sync

### Audio
- Volume général
- Volume musique
- Volume effets sonores

### Contrôles
- Remappage complet des touches
- Sensibilité de la souris

### Jeu
- Difficulté
- Paramètres spécifiques au gameplay

## 📝 License

Voir le fichier [LICENSE](LICENSE) pour plus de détails.

## 👨‍💻 Développement

### Compilation avec couverture de code
```bash
make unit_tests
```

### Nettoyage
```bash
make clean      # Supprime les fichiers objets
make fclean     # Supprime tout sauf les sources
make re         # Recompile entièrement
```

## 🔧 Dépendances

- **CSFML** - Rendu graphique, gestion des fenêtres et audio
- **Math.h** - Calculs mathématiques pour le raycasting
- **Criterion** - Framework de test (optionnel)

---

**Créé en 2025** - EPITECH PROJECT
