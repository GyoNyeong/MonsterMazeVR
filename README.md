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
- **구현**
  - DFS(Depth-First Search) 알고리즘을 활용하여 미로의 통로를 생성했습니다.
  - 벽과 통로를 관리하기 위해 2차원 배열(MazeArray)을 사용하였으며, 초기화 과정에서 모든 셀을 벽으로 설정한 후, DFS를 통해 통로를 개척했습니다.
- **해결한 문제** 
  - 무작위성 구현과 데이터 관리, 플레이어가 항상 출구에 도달할 수 있는 경로를 보장했습니다.

---

### 2. 몬스터 및 아이템 배치 로직
- **동기:** 플레이어가 다양한 도전 과제와 보상을 경험하도록 설계.
- **구현:**
  - 미로 생성 후, 빈 공간을 탐색하여 EmptyLocation 배열에 저장했습니다. 그 후, SpawnActors 함수를 통해 지정된 개수만큼 몬스터, 아이템, 트랩을 랜덤하게 배치했습니다.
- **해결한 문제** 
  - 아이템과 몬스터의 배치는 빈 공간 좌표를 사용하여 관리했습니다. 이를 통해 몬스터와 아이템이 중복 배치되지 않도록 하였으며, 미로 전체에 배치할 수 있었습니다.

---

### 3. VR 인터랙션 기능
- **동기:** VR 환경에서 플레이어의 몰입감을 높이기 위해 상호작용 가능한 게임 환경을 설계.
- **구현:** VR
  - 컨트롤러 입력을 처리하여 아이템 집기, 트랩 해제, 포털 활성화와 같은 동작을 지원했습니다.
  - Unreal Engine의 Motion Controller Component를 사용하여 VR 기기의 입력을 처리하고, 이를 기반으로 커스텀 이벤트를 구현했습니다.

---

### 4. 미로 생성 성능 개선
- **동기:** 미로 크기와 동적 생성 요소가 많아질수록 발생하는 성능 저하를 방지. 특히, 대형 미로(예: 101x101)에서의 로딩 시간과 프레임 드랍 문제발생.
- **구현**
  - **데이터 관리** : 미로의 벽과 통로 상태를 관리하기 위해 2차원 배열`MazeArray`을 사용하였습니다. 배열 기반의 데이터 구조는 메모리 접근 패턴을 최적화하여 캐시 효율성을 높이고, 데이터 조회 및 수정 속도를 개선합니다.
  - **객체 스폰 관리** : `SpawnManager` 함수를 통해 필요한 객체만을 효율적으로 스폰하도록 설계했습니다. 또한, 동일한 타입의 객체를 그룹으로 스폰하여 `SpawnActor` 호출 횟수를 줄이고, 불필요한 객체 생성을 방지했습니다.
- **추가 개선 사항**
  - **객체 풀링** : 빈번한 SpawnActor 호출로 인한 성능 저하를 방지하기 위해 객체 풀링 기법을 도입할 수 있습니다. 이는 사전에 일정 수의 객체를 생성해 두고 필요할 때 재사용함으로써 객체 생성과 소멸에 따른 오버헤드를 줄이는 방법으로써 향후 적용을 고려하고 있습니다.

---

<br>

## 📊 결과
- DFS 기반 랜덤 미로 생성과 AI 몬스터 구현. VR 환경에서의 몰입감 있는 게임플레이 제공.

## 📊 개선 사항
- 미로 크기와 난이도 설정 기능 추가.
- 멀티플레이어 모드 지원.
- 몬스터 및 아이템의 다양성 확대.
- VR 인터랙션에서 피드백 효과 추가.

---
