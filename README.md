MonsterMaze
VR 콘텐츠 프로젝트: 몬스터를 피해 무한한 미로를 탈출하는 게임

<br>
<br>
🗂️ 프로젝트 개요
진행 기간	2024.10.01 ~ 2024.11.30
핵심 기술	랜덤 미로 생성, 객체 스폰 시스템, AI 몬스터 FSM
개발 환경	UnrealEngine 5, C++, Visual Studio, GitHub
플랫폼	PC VR
YouTube 데모 영상	(직접 작성 예정)
<br>
<br>
📂 개발 내용
<div style="text-align: center;"> <h3>MonsterMaze - 미로 생성 및 게임플레이</h3> <img src="https://github.com/user-attachments/assets/maze_example.png" alt="MonsterMaze Example" width="600"> </div> <br>
<br>
01. 랜덤 미로 생성 시스템
알고리즘:
DFS 기반으로 미로를 랜덤 생성.
CarveMazeDFS()를 사용하여 미로의 벽과 통로를 동적으로 결정.
구현 내용:
미로는 2D 배열(MazeArray)로 관리되며, 각 칸은 벽 또는 통로로 정의.
SpawnManager를 통해 미로의 벽과 주요 객체를 스폰.
결과:
실행 시마다 고유한 미로를 생성, 리플레이 가치를 높임.
<br>
<br>
02. 객체 스폰 시스템
구현 내용:
SpawnActors()와 SpawnManager()를 사용해 미로 내 빈 공간에 무작위로 객체를 배치.
객체 유형:
플레이어 시작 위치 (PlayerStart)
탈출구 (ExitPortal)
몬스터 (WarriorMonster, MageMonster)
아이템 (총기, 포션, 함정)
특징:
빈 공간 탐색 후 객체를 배치하여 충돌 방지 및 균일한 분포를 보장.
스폰 시 Tick 호출 비활성화로 성능 최적화.
<br>
<br>
03. 몬스터 AI 및 유한 상태 머신 (FSM)
FSM 구성:
몬스터의 상태는 순찰(Patrol), 추적(Chase), **공격(Attack)**으로 나뉨.
상태 전환은 플레이어와의 거리 및 가시성에 따라 결정.
구현 내용:
플레이어와의 상호작용을 기반으로 상태를 실시간 업데이트.
AI 몬스터는 플레이어를 추격하며 적절한 공격 패턴을 사용.
결과:
현실감 있는 AI 행동으로 게임의 몰입감 향상.
<br>
<br>
04. 플레이어 상호작용 시스템
구현 내용:
총기 및 아이템:
총기를 사용해 몬스터를 제압 가능.
포션으로 체력 회복, 함정을 피해 이동.
탈출구:
미로 끝의 탈출구를 찾으면 게임이 종료.
결과:
VR 컨트롤러를 활용한 자연스러운 게임플레이 구현.
<br>
<br>
05. 최적화 및 성능 개선
Tick 비활성화:
불필요한 객체의 Tick 호출을 제거해 성능 최적화.
스폰 및 메모리 관리:
객체가 스폰된 후 메모리 효율적으로 관리.
결과:
VR 환경에서도 부드러운 프레임 유지.
<br>
<br>
🛠️ 설치 및 실행 방법
프로젝트 클론:
bash
코드 복사
git clone [깃 주소]
언리얼 엔진 5로 프로젝트 열기.
Build 버튼을 클릭하여 게임 실행.
<br>
<br>
📊 프로젝트 결과 및 개선 사항
결과:
DFS 기반 랜덤 미로 생성과 AI 상호작용 시스템 구현.
VR 환경에서의 몰입감 있는 게임플레이 제공.
개선 사항:
몬스터 유형과 AI 상태 추가.
미로의 난이도 동적 조절 기능 구현.
<br>
<br>
📂 주요 코드
랜덤 미로 생성
cpp
코드 복사
void AMazeGenerator::CarveMazeDFS(int X, int Y)
{
    MazeArray[X][Y] = false; // 현재 위치를 통로로 설정
    TArray<int32> Directions = { 0, 1, 2, 3 }; // 방향 설정 (북, 동, 남, 서)

    for (int32 i = 0; i < 4; i++)
    {
        int RandomDirectionIndex = FMath::RandRange(0, Directions.Num() - 1);
        int Direction = Directions[RandomDirectionIndex];
        // (로직 생략)
    }
}
<br>
<br>
📽️ 프로젝트 미리보기
YouTube 데모 영상: (직접 작성 예정)
