StrangeMatrix transpose(StrangeMatrix m) {
    StrangeMatrix m1;
    m1.first_line[0] = m.first_line[0];
    m1.second_line[1] = m.second_line[1];
    m1.third_line[2] = m.third_line[2];
    m1.first_line[1] = m.second_line[0];
    m1.first_line[2] = m.third_line[0];
    m1.second_line[0] = m.first_line[1];
    m1.second_line[2] = m.third_line[1];
    m1.third_line[0] = m.first_line[2];
    m1.third_line[1] = m.second_line[2];
    return m1;
}
