#ifndef GENERIC_DISTANCE
#define GENERIC_DISTANCE

float generic_distance(string method, point q0, point q1, float m)
{
    vector span = q0-q1;
    if (method == "distance squared") {
        return dot(span,span);
    }
    if (method == "distance") {
        return length(span);
    }
    else if (method == "manhattan") {
        return max(
            max(
                abs(span[0]),
                abs(span[1])
            ),
            abs(span[2])
        );
    }
    else if (method == "chebichew") {
        return
            abs(span[0]) +
            abs(span[1]) +
            abs(span[2]);
    }
    else if (method == "minkowsky") {
        return pow(
            abs( pow(span[0], m) ) +
            abs( pow(span[1], m) ) +
            abs( pow(span[2], m) ),
            1.0/m);
    }
}

#endif
