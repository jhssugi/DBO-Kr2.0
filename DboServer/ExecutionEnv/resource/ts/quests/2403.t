CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 8;
	rq = 0;
	tid = 2403;
	title = 240302;

	CNtlTSGroup
	{
		gid = 0;

		CDboTSContGAct
		{
			cid = 2;
			elnk = 252;
			nextlnk = 100;
			prelnk = "1;";

			CDboTSActNPCConv
			{
				conv = 240309;
				ctype = 1;
				idx = 4072302;
				taid = 2;
			}
			CDboTSActRegQInfo
			{
				cont = 240308;
				gtype = 1;
				area = 240301;
				goal = 240304;
				grade = 132203;
				rwd = 100;
				scitem = -1;
				sort = 240305;
				stype = 2;
				taid = 1;
				title = 240302;
			}
		}
		CDboTSContEnd
		{
			cid = 254;
			prelnk = "100;";
			type = 1;
		}
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "0;1;252;";
			type = 0;
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 240308;
			gtype = 1;
			oklnk = 2;
			area = 240301;
			goal = 240304;
			sort = 240305;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 240302;
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 240314;
			nextlnk = 254;
			rwdexp = 0;
			rwdtbl = 240301;
			rwdtype = 0;
			ltime = -1;
			prelnk = "2;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "6412111;";
			}
		}
		CDboTSContGAct
		{
			cid = 252;
			elnk = 255;
			nextlnk = 253;
			prelnk = "2;";
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 240307;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 52;
			}
			CDboTSCheckClrQst
			{
				and = "2402;";
				flink = 1;
				flinknextqid = "2404;";
				not = 0;
			}
			CDboTSClickNPC
			{
				npcidx = "4072302;";
			}
		}
	}
}

