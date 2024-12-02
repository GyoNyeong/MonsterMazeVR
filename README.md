# MonsterMaze

VR 콘텐츠 프로젝트: 몬스터를 피해 무한한 미로를 탈출하는 게임

<br>

---

<br>

## 🗂️ **프로젝트 개요**

| **진행 기간**       | 2024.09.11 ~ 2024.09.23                |
|---------------------|---------------------------------------|
| **핵심 기술**       | 랜덤 미로 생성, 객체 스폰 시스템 |
| **팀 규모**       | 팀 프로젝트 총 2명 / 개발자 : 최무성, 박교녕 |
| **개발 환경**       | UnrealEngine 5, C++, GitHub, Oculus SDK |
| **플랫폼**          | PC VR                                 |
| **YouTube 데모 영상** | (작성 예정)                        |

<br>

---

<br>

# MonsterMaze

## 프로젝트 개요
MonsterMaze는 플레이어가 무작위로 생성된 미로에서 몬스터를 피해 출구를 찾는 VR 게임입니다. 이 프로젝트는 동적 미로 생성 시스템과 VR 환경 상호작용, AI 몬스터 등을 활용해 몰입감 있는 게임플레이를 제공합니다.

<br>

---

<br>

## 주요 기능
- **랜덤 미로 생성:** DFS(Depth-First Search) 알고리즘을 활용한 동적 미로 생성.
- **AI 몬스터:** 플레이어를 추적하며 방해하는 몬스터 AI.
- **VR 인터랙션:** VR 컨트롤러로 아이템 조작, 트랩 해제 등 상호작용.
- **아이템 및 트랩 배치:** 미로 내 랜덤으로 배치된 체력 포션, 무기, 트랩 등.
- **출구 포털 시스템:** 미로 탈출을 위한 목표점인 포털 배치.

<br>

---

<br>

## 개발 포인트

### 1. 랜덤 미로 생성 시스템
- **동기:** 플레이어에게 매번 새로운 경험을 제공하기 위해 랜덤한 미로를 생성.
- **구현:** DFS 알고리즘으로 미로의 통로를 생성하고, 벽과 통로를 효율적으로 관리하기 위해 2차원 배열을 사용했습니다.
- **해결한 문제** 
  - 무작위성 구현과 데이터 관리의 최적화를 통해 플레이어가 항상 출구에 도달할 수 있는 경로를 보장했습니다.

---

### 2. 몬스터 및 아이템 배치 로직
- **동기:** 플레이어가 다양한 도전 과제와 보상을 경험하도록 설계.
- **구현:** 미로 생성 후 빈 공간을 탐색하여 랜덤으로 몬스터, 아이템, 트랩을 배치했습니다. 몬스터 AI는 Behavior Tree와 Blackboard를 활용하여 플레이어를 추적하도록 설계했습니다.
- **해결한 문제** 
  - 아이템과 몬스터의 배치가 게임 밸런스를 해치지 않도록 빈 공간 좌표를 효율적으로 관리했습니다.

---

### 3. VR 인터랙션 기능
- **동기:** VR 환경에서 플레이어의 몰입감을 높이기 위해 상호작용 가능한 게임 환경을 설계.
- **구현:** VR 컨트롤러 입력을 처리하여 아이템 집기, 트랩 해제, 포털 활성화와 같은 동작을 지원했습니다.
- **해결한 문제** 
  - VR 환경에서의 상호작용이 직관적이도록 범위와 동작을 최적화했습니다.

---

### 4. 미로 생성 성능 최적화
- **동기:** 미로 크기와 동적 생성 요소가 많아질수록 발생하는 성능 저하를 방지.
- **구현:** 배열 기반 데이터 관리와 `SpawnActor` 최적화를 통해 성능을 개선했습니다.
- **해결한 문제** 
  - 대형 미로에서도 부드러운 로딩과 게임 플레이가 가능하도록 최적화했습니다.

---

<br>

## 📊 결과
- DFS 기반 랜덤 미로 생성과 AI 상호작용 시스템 구현. VR 환경에서의 몰입감 있는 게임플레이 제공.

## 📊 개선 사항
- 미로 크기와 난이도 설정 기능 추가.
- 멀티플레이어 모드 지원.
- 몬스터 및 아이템의 다양성 확대.
- VR 인터랙션에서 피드백 효과 추가.

---
