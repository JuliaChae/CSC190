class graph:
    def __init__(self):
        # Initiate the store list
        self.store = []
    def addVertex(self, n):
        # Error check
        if n < 0:
            return -1
        else:
            for i in range(0,n):
                self.store = self.store + [[]]
            # Final number of vertices in the graph
            return len(self.store)
    def addEdge(self,from_idx,to_idx, directed, weight):
        while True:
            try:
                if from_idx < 0:
                    return False
                if to_idx < 0:
                    return False
                if from_idx >= len(self.store):
                    return False
                if to_idx >= len(self.store):
                    return False
                if directed == True:
                # Not bidirectional
                    self.store[from_idx].append([to_idx,weight])
                    return True

                elif directed == False:
                # Bidirectional
                    self.store[from_idx].append([to_idx,weight])
                    self.store[to_idx].append([from_idx,weight])
                    return True
                break

            except Exception as e:
                return False
    def traverse(self,start,typeBreadth):
        length = len(self.store)
        accum = []
        sublist = 0
        c = []
        discover = length*[False]
        process = length*[False]
        while True:
            try:
                if start == None:
                    if typeBreadth == True:
                        # Breadth first traversal
                        # Breadth -> queue
                        for i in range(0,length):
                            if discover[i] == False:
                                # Creates a new sublist
                                sublist = sublist + 1
                                accum.append([])
                                #ENQUEUE
                                c = [i] + c
                                discover[i] = True
                            while len(c) != 0:
                                w = c.pop()
                                if process[w] == False:
                                    # Process
                                    accum[sublist-1].append(w)
                                    process[w] = True
                                for x in self.store[w]:
                                    if discover[x[0]] == False:
                                        c = [x[0]] + c
                                        discover[x[0]] = True
                        return accum


                    elif typeBreadth == False:
                    # Depth first traversal
                    # Depth first -> stack
                        for i in range(0,length):
                            if discover[i] == False:
                                sublist = sublist + 1
                                accum.append([])
                                c = c + [i]
                                discover[i] = True
                            while len(c) != 0:
                                w = c.pop()
                                if process[w] == False:
                                    # Process
                                    accum[sublist - 1].append(w)
                                    process[w] = True
                                for x in self.store[w]:
                                    if discover[x[0]] == False:
                                        c = c + [x[0]]
                                        discover[x[0]] = True
                        return accum

                # Partial traversal
                elif start != None:
                    if start < 0 or start > length-1:
                        # Error statement
                        return []
                    else:
                        discover = length * [False]
                        process = length * [False]
                        # Change the line: for v in V
                        if typeBreadth == True:
                            # Breadth first traversal
                            # Breadth -> queue
                            if discover[start] == False:
                                # Creates a new sublist
                                # ENQUEUE
                                c = [start] + c
                                discover[start] = True
                            while len(c) != 0:
                                w = c.pop()
                                if process[w] == False:
                                    # Process
                                    accum.append(w)
                                    process[w] = True
                                for x in self.store[w]:
                                    if discover[x[0]] == False:
                                        c = [x[0]] + c
                                        discover[x[0]] = True
                            return accum

                        elif typeBreadth == False:
                            # Depth first traversal
                            # Depth first -> stack
                            if discover[start] == False:
                                # Creates a new sublist
                                # stack
                                c = c + [start]
                                discover[start] = True
                            while len(c) != 0:
                                w = c.pop()
                                if process[w] == False:
                                    # Process
                                    accum.append(w)
                                    process[w] = True
                                for x in self.store[w]:
                                    if discover[x[0]] == False:
                                        c = c + [x[0]]
                                        discover[x[0]] = True
                            return accum
            except Exception as e:
                return []

    def connectivity(self,vx,vy):
        rval = [None,None]
        vxtovy = 0
        vytovx = 0
        traversal_vxtovy = self.traverse(vx,False)
        traversal_vytovx = self.traverse(vy,False)
        for i in traversal_vxtovy:
            if i == vy:
                vxtovy = 1
                break
        for i in traversal_vytovx:
            if i == vx:
                vytovx = 1
                break
        if vxtovy == 0:
            rval[0] = False
        if vxtovy == 1:
            rval[0] = True
        if vytovx == 0:
            rval[1] = False
        if vytovx == 1:
            rval[1] = True
        return rval
    def pathDFS(self,v,goal,explored,path_so_far):
        explored[v] = True
        if v == goal:
            return path_so_far + [goal]
        for w in self.store[v]:
            if explored[w[0]] == False:
                p = self.pathDFS(w[0],goal,explored,path_so_far+[v])
                if p:
                    return p
    def path(self,vx,vy):
        length = len(self.store)
        discover = length * [False]
        process = length * [False]
        c = []
        rval = [None,None]
        check = self.connectivity(vx,vy)
        if check[0] == False and check[1] == False:
            discover = length * [False]
            process = length * [False]
            return [[],[]]
        if check[0] == False and check[1] == True:
            discover = length * [False]
            process = length * [False]
            rval[0] = []
            discover = length * [False]
            process = length * [False]
            rval[1] = self.pathDFS(vy,vx,discover,c)
            return rval
        if check[0] == True and check[1] == False:
            discover = length * [False]
            process = length * [False]
            rval[0] = self.pathDFS(vx,vy,discover,c)
            discover = length * [False]
            process = length * [False]
            rval[1] = []
            return rval
        if check[0] == True and check[1] == True:
            discover = length * [False]
            process = length * [False]
            rval[0] = self.pathDFS(vx, vy, discover, c)
            discover = length * [False]
            process = length * [False]
            rval[1] = self.pathDFS(vy, vx, discover, c)
            return rval

