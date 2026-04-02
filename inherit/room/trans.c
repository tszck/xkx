// trans.c

// #pragma save_binary

#include <room.h>
#include <ansi.h>

inherit ROOM;

void init_connections();

// 交通要點，所有交通信息保存在 MAP_D 中，本地連接情況保存在
// F_DBASE 中的 trans 變量中，前爲所去地點，後爲價格。

// 提示給顧客的信息
string trans_prompt()
{
        string msg;
        mapping trans;
        string to;
	int i;
        mixed pos;

        if (! mapp(trans = query("trans")) || sizeof(trans) < 1)
                return "本店正在維修中，暫時不提供交通服務。\n";

        msg = WHT "本店現在開通了去以下地方的通路：\n" HIY
              "----------------------------------------\n" NOR;
	for (i = 0; i < sizeof(keys(trans)); i++)
        {
		if (to == keys(trans)[i])
		{
	                if (! mapp(pos = MAP_D->query_trans_info(to)))
				continue;
			msg += sprintf(" %-17s %s\n", pos["name"] + "(" + to + ")", MONEY_D->price_str(trans[to]));
		}
        }

/*
        foreach (to in keys(trans))
        {
                if (! mapp(pos = MAP_D->query_trans_info(to)))
                        continue;

                msg += sprintf(" %-17s %s\n",
                               pos["name"] + "(" + to + ")",
                               MONEY_D->price_str(trans[to]));
        }
*/
        msg += HIY "----------------------------------------\n" NOR
               WHT "即來即走(" HIY "goto" NOR + WHT ")無"
               "需等待，兒童一律免費。\n" NOR;

        return msg;
}

void setup()
{
        ::setup();
        init_connections();
}

// 初始化連接
void init_connections()
{
        mapping trans;
        mixed   conn;
        mixed   item;
        mapping pos;
        string  here;
	int i;

        pos = MAP_D->query_trans_info();
/* 替代 foreach */
	for (i = 0; i < sizeof(keys(pos)); i++)
	{
		if (item == keys(pos)[i])
		{
			if (stringp(pos[item]["room"]) &&
				find_object(pos[item]["room"]) == this_object())
			{
			// 確定了自己的位置
				here = item;
				break;
			}
		}
	}
/*
        foreach (item in keys(pos))
        {
                if (stringp(pos[item]["room"]) &&
                    find_object(pos[item]["room"]) == this_object())
                {
                        // 確定了自己的位置
                        here = item;
                        break;
                }
        }
*/
        if (here && arrayp(conn = MAP_D->query_connect_info()))
        {
                trans = ([ ]);
/* 替代 foreach */
		for (i = 0; i < sizeof(conn); i++)
		{
			if (item == conn[i])
				if(item[0] == here) trans[item[1]]=item[2];
				else if(item[1] == here) trans[item[0]]=item[2];
		}
/*
                foreach (item in conn)
                        if (item[0] == here)
                                trans[item[1]] = item[2];
                        else
                        if (item[1] == here)
                                trans[item[0]] = item[2];
*/
                if (sizeof(trans))
                        set("trans", trans);
        }
        set("item_desc/paizi", trans_prompt());
}

void init()
{
      add_action("do_goto", "goto");
}

int do_goto(string arg)
{
        mixed  pos;
        object me;
        object cart;
        object *obs;
        int pay;

        if (! arg)
                return notify_fail("你要去哪裏？\n");

        if (undefinedp(pay = query("trans/" + arg)))
                return notify_fail("看清楚牌子(paizi)，上面哪裏有這個地方？\n");

        me = this_player();

        if (me->is_busy())
                return notify_fail("什麼都等你忙完了再說吧。\n");

        pos = MAP_D->query_trans_info(arg);

        if (! mapp(pos) || ! stringp(pos["name"]))
        {
                write("馬伕大呼道：“BUG！BUG！”\n");
                return 1;
        }

        if (! stringp(pos["room"]))
        {
                write(CYN "馬伕苦笑道：“那個地方去不了哦。”\n" NOR);
                return 1;
        }

        if (wiz_level(me) > 0)
        {
                write(CYN "馬伕笑道：原來是巫師啊，你不會飛麼？既然非"
                      "要走路，那就不收錢了。\n" NOR);
                pay = 0;
        } else
        if (me->query("family/family_name") == "段氏皇族")
        {
                pay = 0;
                write(CYN "馬伕道：呦，是您啊，您就走吧，我怎好意思收"
                      "您的錢。\n" NOR);
        } else
        if (me->query("age") <= 14)
        {
                pay = 0;
                write(CYN "馬伕訝道：小小年紀就出來了？算了，我就不收"
                      "你的錢了。\n" NOR);
        } else
        if (me->query_skill("higgling", 1) >= 30)
        {
                pay = pay * 100 / (me->query_skill("higgling", 1) + 100);
                switch (random(5))
                {
                case 0:
                        write("你道：看在我常年照顧你生意份上，還不給點折扣？\n");
                        break;

                case 1:
                        write("你道：你們老闆可是我的熟人啊。\n");
                        break;

                case 2:
                        write("你道：這位兄弟好，最近生意好吧，給點折扣如何？\n");
                        break;

                case 3:
                        write("你道：太貴了，便宜點，便宜點我就走了。\n");
                        break;

                case 4:
                        write("你道：我這是急事，您就行個好，便宜點吧。\n");
                        break;
                }

                pay /= 10;
                pay *= 10;
                if (pay < 10) pay = 10;
                write(CYN "馬伕無奈道：“好吧，好吧，那就" + MONEY_D->price_str(pay) +
                      CYN "算了。”\n" NOR);
        }

        if (pay > 0)
        {
                if (MONEY_D->player_pay(me, pay) != 1)
                {
                        write(CYN "馬伕皺了皺眉頭，說道：小本經營，概不"
                              "賒帳，準備好零錢再來。\n" NOR);
                        return 1;
                }

                message_vision(WHT "$N" WHT "付了帳，對馬伕說了兩句什麼。\n"
                               NOR, me);
        }

        message_vision(HIC "馬伕一聲招呼，開過來一輛大車，$N"
                       HIC "上了車就出發了。\n" NOR, me);
        cart = new("/clone/misc/trans_cart");
        obs = filter_array(all_inventory(),
                           (: $1 == $(me) || $1->query_leader() == $(me) &&
                                          ! userp($1) &&
                                          ! $1->is_killing($(me)->query("id")) :));
        obs->move(cart);
        me->start_call_out((: call_other, __FILE__, "arrival", me, cart, pos :), 2);
        return 1;
}

void arrival(object me, object cart, mapping pos)
{
        object *obs;

        if (! objectp(me) || ! objectp(cart))
                return;

        if (environment(me) != cart)
                return;

        obs = filter_array(all_inventory(cart),
                           (: $1 == $(me) || $1->query_leader() == $(me) &&
                                          ! userp($1) &&
                                          ! $1->is_killing($(me)->query("id")) :));

        tell_object(me, HIY "你到了" + pos["name"] + HIY "，下了車。\n" NOR);

        obs->move(pos["room"]);

        message("vision", "吱呀吱呀一輛大車趕了過來，隨即就見" +
                          me->name() + "跳了下來。\n",
                          environment(me), me);

        if (sizeof(obs = all_inventory(cart)) > 0)
        {
                message("vision", WHT "只聽稀里嘩啦一陣響，從車上扔下"
                                  "一堆東西來。\n" NOR, me);
                obs->move(pos["room"]);
        }

        if (objectp(cart))
                destruct(cart);
}

void reset()
{
        ::reset();
        init_connections();
}
