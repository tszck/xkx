// Room: /d/wudujiao/mishi.c
// Last modified by ahda  Jul 17 2001
// Ln67 面壁五毒神功沒加上限限制，暫時先限制在180~200

inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
這裏是一座不大的石室，房間落滿灰塵，好象有多年沒人打掃似
的。室內只有一牀一案，一縷陽光從洞頂的巖縫中射入，室內光線明
亮。牆邊有一個青石牀(bed)，與旁邊石壁的色澤有很大不同。透過
斜射的陽光，你看到石牀對面牆壁上似乎刻着一些文字和圖形。一個
寬大的石案上擺着一個石匣(xia)。
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);
	set("no_clean_up", 0);
        set("exits", ([
                "eastup" : __DIR__"shixi",
        ]));
        set("item_desc",([
         "wall":"\n       只見石壁上刻着“千蛛萬毒”四個龍飛鳳舞的大字。\n
       下面有三個盤膝而坐的人像，刻得栩栩如生，每個人姿勢都不相同。\n
       旁邊還有許多小字,你不妨照着練習(lianxi)一下。\n ",
         "牆壁":"\n       只見石壁上刻着“千蛛萬毒”四個龍飛鳳舞的大字。\n
       下面有三個盤膝而坐的人像，刻得栩栩如生，每個人姿勢都不相同。\n
       旁邊還有許多小字，你不妨照着練習(lianxi)一下。\n ",
         "bed":"\n一個普普通通的石牀。\n ",
         "xia":"\n一隻石匣，好象是和石案連在一起的，不知道敢不敢打開看看。\n ",
        ]));
        set("mishi_book",1);
        set("coor/x", -44960);
	set("coor/y", -81120);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_lianxi", "lianxi");
        add_action("do_jump", "jump");
        add_action("do_open", "open");
}

int do_lianxi(string arg)
{
        object weapon;
        object me=this_player();
        int forceskill=(int)me->query_skill("force", 1);
        int wuduskill=(int)me->query_skill("wudu-shengong", 1);
        int maxlevel, exp=(int)me->query("combat_exp");
        if( me->query("jing") < (int)(me->query("max_jing")/5))
            return notify_fail("你已經沒有精力練習了！\n");
        if (!((string)me->query("family/family_name")=="五毒教")
            || !(int)me->query_temp("wudu_onbed"))
        {
        message_vision("$N盤膝而坐，照着壁上的圖形練了幾次，只覺得一陣口乾舌燥。\n", me);
        }
        else
        {
        message_vision("$N照着壁上圖形的姿勢盤膝坐下，很快就靜下心來。\n", me);
            if (exp*10 <= (wuduskill*wuduskill*wuduskill))
            {
                me->receive_damage("qi", 30);
                return notify_fail("但是你的經驗不夠，始終不能從圖中領悟到什麼。\n");
            }
            if (wuduskill > 179 & forceskill>150 & wuduskill < 200 )
            {
                me->improve_skill("wudu-shengong", 2*(int)(me->query("int")+me->query_skill("literate")));
                tell_object(me, "你似乎從中領悟出一些五毒神功方面的竅門。\n");
            }
            else
            {
                tell_object(me, "你的功夫太低了，還不能領會圖形所載的練功法門。\n");
            }
        }
        me->receive_damage("jing", 20);
        return 1;
}
int do_jump(string arg)
{
        object me=this_player();
        if( !arg ||! (arg =="bed" || arg =="up" || arg =="down"))
            return 0;
        if( arg =="up"||arg=="bed"){
            if ((int)me->query_temp("wudu_onbed") )
                return notify_fail("你已經在牀上了，再跳就碰到洞頂了。\n");
            me->set_temp("wudu_onbed",1);
            message_vision("$P輕輕一縱跳上了石牀，坐了下來。\n", me);
            tell_object(me, "你只覺得一絲絲涼氣從身下傳來，頓絕精神一振。\n");
        }
        if( arg =="down"){
            if (!(int)me->query_temp("wudu_onbed") )
                return notify_fail("你已經在地下了，亂蹦亂跳成何體統？\n");
            me->delete_temp("wudu_onbed");
            message_vision("$P從石牀上跳了下來。\n", me);
        }
        return 1;
}
int valid_leave (object me, string dir)
{
        if (me->query_temp("wudu_onbed"))
            return notify_fail("先下牀再走，連走路也不會嗎？\n");
        return 1;
}
int do_open(string arg)
{
        object me,ob;
        me=this_player();
        if( !arg || arg !="xia")
            return 0;
        if( query("mishi_book") < 1)
            return notify_fail("你打開石匣。但見裏面空空如也。\n");
        add("mishi_book", -1);
        message_vision("$P打開石匣，從裏面取出一束絹冊。\n", me);
        ob = new("/clone/book/poisonbook3");
        ob->move(me);
        return 1;
}

