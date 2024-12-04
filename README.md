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

## __나의 작업__

1. 몬스터 제작
    
   1.1. AI 컨트롤러 제작
    
    -상태 관리 Enum 생성
    -AI 컨트롤러 생성 및 AI Perception Component 추가
    -OnTargetPerceptionUpdated 노드에서 타겟을 감지했을 때, 감지대상을 블랙보드의 TargetActor에 Set. 몬스터의 상태를 변경
    -Perception에서는 시야를 사용하도록 설정
    
   1.2. BehaviorTree 및 Blackboard 생성
    
   -BTTask_CheckAttack을 이용해 TargetActor와 자신의 거리를 계산하여 상태를 Chase와 Attack으로 변경해 TargetActor와 일정거리가 멀어지면 다시 Target을 따라가도록 구현

   1.3. 공격 설정

    -몬스터의 블루프린트에서 블랙보드에 설정된 상태를 주기적으로 체크하도록하고 Attack 상태가 되었을 때 PlayAnimMontage노드를 이용해 특정한 애니메이션이 실행되도록 설정
    -AnimMontage를 사용할 수 있도록 AnimBlueprint에서 Slot 추가

1. 아이템 구현
    
    2.1 총알
    
    -총알의 BeginOverlap 이벤트에서 OvelappedActor를 몬스터로 캐스팅해 몬스터의 HP를 자기의 데미지만큼 뺴는 방식으로 구현
    -데미지를 줄 떄 몬스터의 HP를 검사하여 HP가 0보다 작거나 같다면 몬스터를 파괴
    
    2.2 힐포션
    
    -힐포션을 잡고 자신에게 가까이 가지고 오면 HealingPoint라는 변수만큼 체력을 회복
    
    -후에 변수의 값을 조절하여 게임 밸런스 조절이 용이하도록 설계
    
    2.3 탄창
    
    -무기는 기본적으로 30발의 총알을 가지고 있는데 탄창을 자신에게 가까이 가지고 오면 남은 탄창수에 상관없이 ReloadBulletCount의 변수 값만큼 총알 수 변경
    
    -후에 변수의 값을 조절하여 게임 밸런스 조절이 용이하도록 설계
    

---

## 작업 간 애로사항 및 작업 후 느낀점

1. 몬스터의 BehaviorTree를 작업할 떄 Navimesh가 존재함에도 Moveto 노드가 작동하지 않던 상황이 발생
    
    -문제점을 찾아봤지만 찾지 못하고 NaviMesh가 없어도 이동하는 MoveDirectlyToward 노드를 사용
    
    -원거리 몬스터의 사정거리를 늘려 이동하지 않고도 공격하도록 수정
    
    -MoveTo는 NaviMesh를 이용해 장애물등을 계산.MoveDirectlyToward는 단순히 직선으로 이동하는 차이
    
2. VR환경에서 UI구현
    
    -VR환경에서는 Hud는 시야에 맞지 않는 문제가 발생해 다른 방식으로 구현해야 했음
    
    -플레이어 폰에 위젯컴포넌트를 부착해 위치를 조정하는 식으로 UI를 구현
    
    -위젯이 벽에 가려져서 안보이거나 하는 등의 문제가 여전히 존재
