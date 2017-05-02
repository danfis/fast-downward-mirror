#ifndef EVALUATORS_G_EVALUATOR_H
#define EVALUATORS_G_EVALUATOR_H

#include "../evaluator.h"

class Heuristic;

namespace g_evaluator {
class GEvaluator : public Evaluator {
public:
    GEvaluator() = default;
    virtual ~GEvaluator() override = default;

    virtual EvaluationResult compute_result(
        EvaluationContext &eval_context) override;

    virtual void get_involved_heuristics(std::set<Heuristic *> &) override {}
};
}

#endif
