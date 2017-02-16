//
// Created by Stephen Clyde on 2/3/17.
//

#include "EdgeTester.hpp"

#include <iostream>
#include <cmath>
#include "../Point.hpp"
#include "../Edge.hpp"
#include "../Utils.hpp"

void EdgeTester::testEdge01()
{
    std::cout << "Execute EdgeTester::testEdge01" << std::endl;

    Point p0(0,0,0);
    Point p1(1,0,0);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (e.getLength()!=1)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 1)"
                  << std::endl;
        return;
    }

    if (e.getSlopeX()!=INFINITY)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting INFINITY)"
                  << std::endl;
        return;
    }

    if (e.getSlopeY()!=0)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0)"
                  << std::endl;
        return;
    }

    if (e.getSlopeZ()!=0)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 0)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testEdge02()
{
    std::cout << "Execute EdgeTester::testEdge02" << std::endl;

    Point p0(1,0,0);
    Point p1(3,4,5);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (fabs(e.getLength() - 6.708203932) > 0.001)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 6.708203932)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeX() - 0.312347524) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting 0.312347524)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeY() - 0.742781353) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0.742781353)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeZ() - 1.118033989) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 1.118033989)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testParallelEdges()
{
    std::cout << "Execute EdgeTester::testParallelEdges" << std::endl;
    Point p0(3,0,20);
    Point p1(2,0,10);
    Edge e1(&p0, &p1);
    Point p2(3,0,20);
    Point p3(2,0,10);
    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e2(&p2, &p3);

    if (!e1.isParallelTo(e2))
    {
        std::cout << "Failure in equal slopes (expecting equal)\n"
                << "slope x: " << e1.getSlopeX()
                << " slope x: " << e2.getSlopeX()
                << " slope y: " << e1.getSlopeY()
                << " slope y: " << e2.getSlopeY()
                << " slope z: " << e1.getSlopeZ()
                << " slope z: " << e2.getSlopeZ()
                << std::endl;
        return;
    }

    Point p4(3,0,20);
    Point p5(2,0,10);
    Edge e3(&p4, &p5);
    Point p6(3,0,20);
    Point p7(2,0,10.001);
    Edge e4(&p6, &p7);

    if (!e3.isParallelTo(e4))
    {
        std::cout << "Failure in equal slopes (expecting not equal)\n"
                  << "slope x: " << e3.getSlopeX()
                  << " slope x: " << e4.getSlopeX()
                  << " slope y: " << e3.getSlopeY()
                  << " slope y: " << e4.getSlopeY()
                  << " slope z: " << e3.getSlopeZ()
                  << " slope z: " << e4.getSlopeZ()
                  << std::endl;
        return;
    }
}

void EdgeTester::testNonParallelEdges()
{
    std::cout << "Execute EdgeTester::testNonParallelEdges" << std::endl;
    Point p0(3,0,20);
    Point p1(2,4,10);
    Edge e1(&p0, &p1);
    Point p2(3,3,3);
    Point p3(7,0,8);
    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e2(&p2, &p3);

    if (e1.isParallelTo(e2))
    {
        std::cout << "Failure in equal slopes (expecting not equal)\n"
                  << "slope x: " << e1.getSlopeX()
                  << " slope x: " << e2.getSlopeX()
                  << " slope y: " << e1.getSlopeY()
                  << " slope y: " << e2.getSlopeY()
                  << " slope z: " << e1.getSlopeZ()
                  << " slope z: " << e2.getSlopeZ()
                  << std::endl;
        return;
    }
    Point p4(3,0,20);
    Point p5(2,4,10);
    Edge e3(&p4, &p5);
    Point p6(3,0,21);
    Point p7(2,0,10);
    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e4(&p6, &p7);

    if (e3.isParallelTo(e4))
    {
        std::cout << "Failure in equal slopes (expecting not equal)\n"
                  << "slope x: " << e3.getSlopeX()
                  << " slope x: " << e4.getSlopeX()
                  << " slope y: " << e3.getSlopeY()
                  << " slope y: " << e4.getSlopeY()
                  << " slope z: " << e3.getSlopeZ()
                  << " slope z: " << e4.getSlopeZ()
                  << std::endl;
        return;
    }

}

void EdgeTester::testNonLengthEdges()
{
    std::cout << "Execute EdgeTester::testNonLengthEdges" << std::endl;
    Point p0(3,0,2);
    Point p1(3,0,2);
    Edge e1(&p0, &p1);
    if (e1.isValid())
    {
        std::cout << "Failure in 0 length edges(expecting 0)\n"
                  << "e1.getLength(): " << e1.getLength()

                  << std::endl;
        return;
    }
    Point p2(0,0,2.01);
    Point p3(0,0,2.001);
    Edge e2(&p2, &p3);
    if (e2.isValid())
    {
        std::cout << "Failure in 0 length edges(expecting 0)\n"
                  << "e1.getLength(): " << e1.getLength()

                  << std::endl;
        return;
    }
    Point p4(0,0,-0.0001);
    Point p5(0,0,0.001);
    Edge e3(&p2, &p3);
    if (e3.isValid())
    {
        std::cout << "Failure in 0 length edges(expecting 0)\n"
                  << "e1.getLength(): " << e1.getLength()

                  << std::endl;
        return;
    }
}

void EdgeTester::testBadEdges()
{
    std::cout << "Execute EdgeTester::testBadEdges" << std::endl;
    Point p0("2gg3,0,2");
    Point p1("dd3");
    Edge e1(&p0, &p1);
    if (e1.isValid())
    {
        std::cout << "Created an invalid line1\n"
                  << std::endl;
        return;
    }
    Point p2("0sdf,0,2.g01");
    Point p3("0,0,ff2.001");
    Edge e2(&p2, &p3);
    if (e2.isValid())
    {
        std::cout << "Created an invalid line2\n"
                  << std::endl;
        return;
    }
    Point p4("0dfg,0,-0.0001");
    Point p5("0,ss0,0.gd001");
    Edge e3(&p2, &p3);
    if (e3.isValid())
    {
        std::cout << "Created an invalid line3\n"
                  << std::endl;
        return;
    }

}
