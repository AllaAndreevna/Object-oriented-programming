
    GameBox box7("Box 4", 10, 20, 30);
    GameBox box8("Box 5", 10, 20, 30);
    container.addBox(box7);
    container.addBox(box8);
    assert(container.getBoxes().size() == 3); // должны быть добавлены три коробки
