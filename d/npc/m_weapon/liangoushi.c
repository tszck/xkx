// ROOM lianbianshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "銀鉤洞");
	set("long", @LONG
這裏是玄兵古洞的打造鋼鉤的地方。南疆荒僻，山林隱密，穿過絞
纏交錯的灌木叢，是一眼大石壘成的窯洞，石頭砌了口大竈，火燒得正
旺，洞口潮溼陰暗，水氣瀰漫，洞裏卻乾爽明亮，熱氣灼人。一個小夥
兒懶洋洋地靠在洞壁，兩手交叉放在胸前，嘴裏叼了根狗尾巴草，似笑
非笑地看着你。
LONG  );
	set("exits", ([
		"east" : "/d/wudujiao/wdsl3",
	]));
	set("objects",([
		__DIR__"npc/shigou" :1,
	]));
	set("coor/x", -44980);
	set("coor/y", -81060);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
